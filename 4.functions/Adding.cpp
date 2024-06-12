#include "Adding.h"
#include <iostream>
#include <memory>
using namespace std;

void Adding::print_result() const
{
    std::cout << "This is the result: " << last_result << "\n";
}

void Adding::print_all_results() const
{
    for (const auto &i : all_results)
    {
        std::cout << *i << ", ";
    }
}

void Adding::add(int a, int b)
{
    int res = a + b;
    add_result(make_unique<int>(res));
    last_result = res;
}
void Adding::add_result(unique_ptr<int> x)
{
    // Move ownership
    all_results.push_back(std::move(x));
}

void Adding::add_result(int x)
{
    all_results.push_back(make_unique<int>(x));
}
