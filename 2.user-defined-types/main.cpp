#include <iostream>
#include "calculator.cpp"

int main()
{
    // enum, describe plain vs class + operation
    // use variant
    Calculator calc{"Texas Inst"};
    Calculator::Difference *diff = calc.getDifference(4, 2, 'b');
    if (diff->type == 'b')
    {
        std::cout << diff->value.positive;
    }
    Calculator::Difference *diff2 = calc.getDifference(4, 2, 'v');

    if (diff2->type == 'v')
    {
        std::cout << diff2->value.numDiff;
    }
    Calculator::Difference *diff3 = calc.getDifference(1, 2, 'b');
    if (diff3->type == 'b')
    {
        std::cout << diff3->value.positive;
    }
    return 0;
}