#include <iostream>

#include <dotnetcpp/System/Span.h>

using namespace System;

void RunInterpreterTests()
{
    int* arr;
    Span<int> s(arr, 5);
    std::cout << s.Length() << std::endl;
    std::cout << s.ToString();
}

int main()
{
    RunInterpreterTests();
    return 0;
}
