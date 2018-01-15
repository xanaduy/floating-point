#include <iostream>
#include "TestFloat.h"
#include "../Tools/TestTools.h"

int main()
{
	Float f = 1.5;

	TestFloat::Test();
	TestTools::Test();

	return 0;
}