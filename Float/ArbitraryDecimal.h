

class ArbitraryDecimal
{
public:
	ArbitraryDecimal(float x)
	{
		std::string s = std::to_string(x);
		// std::for_each( s.begin(), s.end(), [](char &c){c - '0';} );
		Normalize();
	}

	void Normalize()
	{
		int first, last;
		for(first = 0; first < digits.length(); ++first)
			if(digits[i] != 0) break;

		for(last = digits.length() - 1; last >= 0; --last)
			if(digits[last] != 0) break;


	}
private:
	std::string digits;
	int decimalPoint = 0;
};