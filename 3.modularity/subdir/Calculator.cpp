#include "Calculator.h"
#include <iostream>

Calculator::Calculator(int lastRes)
{
    // invariants
    if (lastRes < 0)
    {
        throw std::out_of_range("Calculator::Calculator");
    }
    _lastRes = lastRes;
}

int *Calculator::add(int a, int b)
{
    _lastRes = a + b;
    // pointer would not be necessary (small var)
    // but good to only point to the big ones
    int *res = &_lastRes;
    return res;
}
int Calculator::set_last_res(int x)
{
    // let's pretend this could go wrong
    // and needs an error indicator/code
    _lastRes = x;
    if (_lastRes == x)
    {
        return 0;
    }
    return 1;
}