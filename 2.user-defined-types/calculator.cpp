#include <string>

// no int values bc it's a enum class
enum class Operation
{
    add,
    subtract,
    multiply,
    divide
};
Operation &operator++(Operation &op) // operator++
{
    switch (op)
    {
    case Operation::add:
        return op = Operation::subtract;
    case Operation::subtract:
        return op = Operation::multiply;
    case Operation::multiply:
        return op = Operation::divide;
    case Operation::divide:
        return op = Operation::add;
    }
}

class Calculator
{
    // uses size of the bigger one to allocate space
    union DiffValue
    {
        int numDiff;
        bool positive;
    };

public:
    Calculator(std::string brand) : _brand{brand} {}

    // either gives the difference or tells you if the first one is bigger or not
    struct Difference
    {
        char type;
        DiffValue value;
    };

    Difference *getDifference(int a, int b, char type)
    {
        Difference *diff = &_difference;
        diff->type = type;
        std::cout << type;
        if (type == 'v')
        {
            diff->value = {a - b};
        }
        if (type == 'b')
        {
            diff->value = {a > b};
        }
        std::cout << diff->type;
        return diff;
    }

private:
    std::string _brand;
    Difference _difference;
    Operation operation;
};
