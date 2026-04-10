#include <iostream>

#include <dotnetcpp/System/Exception.h>

using namespace System;

void RunInterpreterTests()
{
	throw Exception("Hello, World!");
}

int main()
{
	RunInterpreterTests();
	return 100;
}
