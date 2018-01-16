#include <iostream>
#include "TestFloat.h"
#include "../Tools/TestTools.h"

int main()
{
	int val = 0x87654321;

	std::cout << "val = " << val << std::endl;

	TestFloat::Test();
	TestTools::Test();

	return 0;
}