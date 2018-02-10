#ifndef ARBITRARY_DECIMAL_H
#define ARBITRARY_DECIMAL_H

#include <string>
#include <algorithm>

class ArbitraryDecimal
{
public:
	ArbitraryDecimal(long x);

	ArbitraryDecimal(int x)
	{
		std::string s = std::to_string(x);
		std::for_each( s.begin(), s.end(), [](char &c){c - '0';} );
		Normalize();
	}

	void Normalize()
	{
		int first, last;
		for(first = 0; first < digits.length(); ++first)
			if(digits[first] != 0) break;

		for(last = digits.length() - 1; last >= 0; --last)
			if(digits[last] != 0) break;

		if (first == 0 || (last == digits.length() - 1))
			return;

		std::string s(digits, first, last - first + 1);

		decimalPoint -= digits.length() - (last + 1);
		digits = s;
	}

	std::string ToString() const
	{
		std::string digitStr;
		for (int i = 0; i < digits.length() - 1; i++)
			digitStr.push_back((char)(digits[i] + '0'));
	}

private:
	std::string digits;
	int decimalPoint = 0;
};

#endif ARBITRARY_DECIMAL_H