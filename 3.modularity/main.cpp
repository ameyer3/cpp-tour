#include <iostream>
#include <map>
#include "subdir/Calculator.h"
#include "subdir/Thing.h"

namespace custom
{
    int cout()
    {
        return 1;
    }
}

int main()
{
    std::cout << custom::cout();

    // lets learn about exception handling
    try
    {
        Calculator calc{0};
        std::cout << *calc.add(2, 5);
    }
    catch (std::out_of_range &err)
    {
        std::cerr << err.what() << "\n";
    }
    catch (std::bad_alloc &)
    {
        std::terminate();
    }

    // create a thing for structured binding
    Thing thing = createThing("Hello", 2);
    std::cout << thing.name << ": " << thing.value;

    // loop through a map with structured binding
    std::map<std::string, int> mapEx;
    fillMap(mapEx);

    for (auto &[key, value] : mapEx)
    {
        std::cout << key << ": Before: " << value;
        value++;
        std::cout << " After: " << value;
    }
}
