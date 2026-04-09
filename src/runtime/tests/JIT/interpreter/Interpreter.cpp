#include <iostream>

#include <dotnetcpp/System/Exception.h>

using namespace System;

void RunInterpreterTests()
{
	Nullable<int> i;
	std::cout << i.Value();
}

int main()
{
	RunInterpreterTests();
	return 100;
}
