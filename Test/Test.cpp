#include "bcmath_stl.h"
#include <iostream>

int main()
{
	BCMath::bcscale(4); //Num Decimals
	BCMath test("-5978");

	test ^= 30; //Pow, only integers. Not work decimals.
	std::cout << "Result BigDecimal 1: " << test.toString().c_str() << std::endl;

	test -= 1.23; //sub
	std::cout << "Result BigDecimal 2: " << test.toString().c_str() << std::endl;

	test *= 1.23; //mul
	std::cout << "Result BigDecimal 3: " << test.toString().c_str() << std::endl;

	test *= -1.23; //mul
	std::cout << "Result BigDecimal 4: " << test.toString().c_str() << std::endl;

	BCMath::bcscale(70); //Num Decimals

	BCMath randNum("-5943534512345234545.8998928392839247844353457");
	BCMath pi("3.1415926535897932384626433832795028841971693993751058209749445923078164062862");

	BCMath result1 = randNum + pi;
	BCMath result2 = randNum - pi;
	BCMath result3 = randNum * pi;
	BCMath result4 = randNum / pi;

	std::cout << "Result Super Precision 1: " << result1.toString().c_str() << std::endl;
	std::cout << "Result Super Precision 2: " << result2.toString().c_str() << std::endl;
	std::cout << "Result Super Precision 3: " << result3.toString().c_str() << std::endl;
	std::cout << "Result Super Precision 4: " << result4.toString().c_str() << std::endl;

	//Other example
	BCMath::bcscale(4); //Num Decimals
	std::cout << "Other 1: " << BCMath::bcmul("1000000.0134", "8.0234").c_str() << std::endl;
	std::cout << "Other 2: " << BCMath::bcadd("1000000.0134", "8.0234").c_str() << std::endl;

	std::cout << "Compare 1:  " << BCMath::bccomp("1", "2") << std::endl;
	std::cout << "Compare 2:  " << BCMath::bccomp("1.00001", "1", 3) << std::endl;
	std::cout << "Compare 3:  " << BCMath::bccomp("1.00001", "1", 5) << std::endl;
	std::cout << "Compare 4:  " << (BCMath("1")< BCMath("2")) << std::endl;
	std::cout << "Compare 5:  " << (BCMath("1") <= BCMath("2")) << std::endl;
	std::cout << "Compare 6:  " << (BCMath("1")> BCMath("2")) << std::endl;
	std::cout << "Compare 7:  " << (BCMath("1") >= BCMath("2")) << std::endl;
	std::cout << "Compare 8:  " << (BCMath("2")< BCMath("2")) << std::endl;
	std::cout << "Compare 9:  " << (BCMath("2") <= BCMath("2")) << std::endl;
	std::cout << "Compare 10: " << (BCMath("2")> BCMath("2")) << std::endl;
	std::cout << "Compare 11: " << (BCMath("2") >= BCMath("2")) << std::endl;

	std::cout << "Round 1: " << BCMath::bcround("123.01254").c_str() << std::endl;
	std::cout << "Round 2: " << BCMath::bcround("-123.01254", 3).c_str() << std::endl;
	std::cout << "Round 3: " << BCMath::bcround("123.01254", 2).c_str() << std::endl;
	pi.round(3);
	std::cout << "Round 4: " << pi.toString().c_str() << std::endl;

	BCMath part1("-.123");
	BCMath part2(".123");
	BCMath part3("123");
	std::cout << "Int part 1: " << part1.getIntPart().c_str() << std::endl;
	std::cout << "Dec part 1: " << part1.getDecPart().c_str() << std::endl;
	std::cout << "Int part 2: " << part2.getIntPart().c_str() << std::endl;
	std::cout << "Dec part 2: " << part2.getDecPart().c_str() << std::endl;
	std::cout << "Int part 3: " << part3.getIntPart().c_str() << std::endl;
	std::cout << "Dec part 3: " << part3.getDecPart().c_str() << std::endl;

	return 0;
}
