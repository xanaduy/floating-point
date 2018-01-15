#include "TestFloat.h"

#include <iostream>

namespace TestFloat
{
	void Test()
	{
		std::cout << "Begin TestFloat" << "\n";

		std::cout << "sizeof float = " << sizeof(float) << "\n";
		Float d = 1.5;
		std::cout << "Sign = " << d.Sign() << "\n";
		std::cout << "Exponent = " << d.Exponent() << "\n";
		std::cout << "Significand = " << d.Significand() << "\n";

		std::cout << "End TestFloat" << std::endl;
	}

}