/*
 link: https://codereview.stackexchange.com/questions/139020/addition-of-two-ieee754-32bit-single-precision-floating-point-numbers-in-c
       answered by FirefoxMetzger
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <random>

#define min_float 0x00000000
#define max_float 0xffffffff

#define exponent(x) (x << 1) >> 24
#define mantissa(x) (x << 9) >> 9
#define sign(x) x >> 31

uint32_t add(uint32_t x, uint32_t y) {
	uint32_t result_mantissa;
	uint32_t result_exponent;
	uint32_t result_sign;

	uint32_t different_sign = sign(x) ^ sign(y); //boolean but lets not do any type casting

	// catch NaN
	if (!(exponent(x) ^ 0xFF) && mantissa(x)) return x;
	if (!(exponent(y) ^ 0xFF) && mantissa(y)) return y;

	// catch Inf
	if (!(exponent(x) ^ 0xFF) && !(exponent(y) ^ 0xFF)) {
		// both are inf
		if (different_sign)
			// Inf - Inf
			return 0x7F800000 + 1; // NaN
		else
			// both Inf or -Inf
			return x;
	}
	else if (!(exponent(x) ^ 0xFF)) return x;
	else if (!(exponent(y) ^ 0xFF)) return y;

	// both numbers are non-special
	uint32_t exp_difference;
	if (different_sign) {
		exp_difference = exponent(y) + exponent(x);
	}
	else {
		// no need to account for constant BO
		// beware of underflow
		if (exponent(x) > exponent(y)) exp_difference = exponent(x) - exponent(y);
		else exp_difference = exponent(y) - exponent(x);
	}


	bool x_bigger_abs;
	if (exponent(x) > exponent(y)) x_bigger_abs = true;
	else if (exponent(x) < exponent(y)) x_bigger_abs = false;
	else if (mantissa(x) > mantissa(y)) x_bigger_abs = true;
	else                                x_bigger_abs = false;

	if (!different_sign) {
		//both numbers have same sign (this is a sum)
		result_sign = sign(x);

		if (x_bigger_abs) {
			result_mantissa = (mantissa(x) << 1) + (mantissa(y) << 1) >> exp_difference;
			result_exponent = exponent(x);
		}
		else {
			result_mantissa = (mantissa(y) << 1) + ((mantissa(x) << 1) >> exp_difference);
			result_exponent = exponent(y);
		}
		if (result_mantissa << 31) result_mantissa = (result_mantissa >> 1) + 1;
		else result_mantissa = (result_mantissa >> 1);
	}
	else {
		// this actually is a subtraction

		if (x_bigger_abs) {
			result_sign = sign(x);
			result_exponent = exponent(x);

			// subtract and round to 23 bit 
			// this means making room in our 32bit representation
			result_mantissa = (mantissa(x) << 1) - ((mantissa(y) << 1) >> exp_difference);
		}
		else {
			result_sign = sign(y);
			result_exponent = exponent(y);

			// subtract and round to 23 bit 
			// this means making room in our 32bit representation
			result_mantissa = (mantissa(y) << 1) - ((mantissa(x) << 1) >> exp_difference);
		}

		if (result_mantissa << 31)  result_mantissa = ((result_mantissa >> 1) + 1);
		else result_mantissa = (result_mantissa >> 1);

		// normalize mantissa
		uint32_t temp = result_mantissa << 9;
		for (uint32_t count = 0; count < 23; ++count) {
			if (!((temp << count) >> 31)) {
				result_mantissa <<= ++count; // leading 1, so shift 1 more time
				result_exponent -= count;
				break;
			}
		}
	}
	uint32_t result = result_sign << 31 | result_exponent << 23 | result_mantissa;
	return result;
}

int main() {
	std::ifstream file;
	file.open("data.txt");
	if (!file.is_open()) {
		std::cout << "Could not open file." << std::endl;
	}

	int num_passed = 0, num_failed = 0;

	//for (int num_tests = 0; num_tests < 1000; num_tests++) {
	//	uint32_t number1 = rand() % max_float; // generate a pseudo-random pattern
	//	uint32_t number2 = rand() % max_float; // generate a pseudo-random pattern
	//	float sum = *(float*)&number1 + *(float*)&number2;

	//	// compare resulting binary patterns
	//	if (*(uint32_t*)&sum & add(number1, number2)) {
	//		num_passed++;
	//	}
	//	else {
	//		std::cout << "Expected: " << *(uint32_t*)&sum << " pattern but recieved " << add(number1, number2) << std::endl;
	//		num_failed++;
	//	}
	//}
	//std::cout << "RNG test -- compared to float: Total " << num_passed << " " << "PASSED " << num_failed << " FAILED." << std::endl;

	num_passed = 0;
	num_failed = 0;

	uint32_t i;
	uint32_t a, b, c;
	std::string line;
	while (getline(file, line)) {
		std::istringstream    iss(line);
		//std::cout << line << endl;
		iss >> std::dec >> i;
		iss >> std::hex >> a;
		iss >> std::hex >> b;
		iss >> std::hex >> c;
		iss.clear();

		std::cout << std::hex << a << "  "
			<< std::hex << b << "  "
			<< std::hex << c << "\n";
		std::cout << *((float *)&a) << "  "
			<< *((float *)&b) << "  "
			<< *((float *)&c) << "\n";
		if (c & add(a, b)) {
			num_passed++;
		}
		else {
			num_failed++;
		}
	}
	std::cout << "Hex test -- compared to file:  Total " << num_passed << " " << "PASSED " << num_failed << " FAILED." << std::endl;
	file.close();
}