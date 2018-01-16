#include "TestFloat.h"

#include <iostream>

namespace TestFloat
{
	void Test()
	{
		std::cout << "Begin TestFloat" << "\n";

		std::cout << "sizeof float = " << sizeof(float) << "\n";
		Float f = -1.5;
		std::cout << "Sign = " << f.Sign() << "\n";
		std::cout << "Exponent = " << f.Exponent() << "\n";
		std::cout << "Significand = " << f.Significand() << "\n";

		std::cout << "UInt32Value = " << f.UInt32Value() << "\n";

		Float a = 1.5;
		Float b = 1.5;
		Float c = a + b;
		std::cout << c.Value() << "\n";

		float h = 16.5;
		float k = 1.5;
		float g = h + k;
		std::cout << g << "\n";

		std::cout << "End TestFloat" << std::endl;


	}


}