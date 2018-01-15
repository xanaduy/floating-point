#include "TestFloat.h"

#include <iostream>

namespace TestFloat
{
	void Test()
	{
		std::cout << "Begin TestFloat" << "\n";

		std::cout << "sizeof float = " << sizeof(float) << "\n";
		Float f = 1.5;
		std::cout << "Sign = " << f.Sign() << "\n";
		std::cout << "Exponent = " << f.Exponent() << "\n";
		std::cout << "Significand = " << f.Significand() << "\n";

		std::cout << "End TestFloat" << std::endl;
	}

}