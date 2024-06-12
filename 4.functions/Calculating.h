#include <iostream>
#include <memory>
using namespace std;

class Calculating
{
public:
    virtual void print_result() const = 0; // has to be implemented & cannot change object
    virtual void print_all_results() const = 0;
    virtual void add_result(unique_ptr<int> x) = 0;
    virtual ~Calculating()
    {
    } // destructor
};