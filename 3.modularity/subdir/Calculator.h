#include <iostream>
#include <vector>

class Calculator
{
public:
    Calculator(int lastRes);
    int *add(int a, int b);
    int set_last_res(int x);

private:
    int _lastRes;
};