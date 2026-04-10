#include <iostream>

#include <dotnetcpp/System/Exception.h>

using namespace System;

void RunInterpreterTests()
{
	Nullable<int> i;
	try
	{
		std::cout << i.Value();
	}
	catch(const Exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main()
{
	RunInterpreterTests();
	return 100;
}
