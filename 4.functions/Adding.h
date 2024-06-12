#include "Calculating.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Adding : public Calculating
{
public:
    void print_result() const; // has to be implemented & cannot change object
    void print_all_results() const;
    ~Adding()
    {
        // only raw pointers need to be deleted manually
        // really wouldn't be needed here since i have nothing to delete
        std::cout << "\nObj destroyed\n";
    } // destructor

    void add(int a, int b);
    void add_result(unique_ptr<int> x);
    void add_result(int x);

private:
    int last_result;
    std::vector<unique_ptr<int>> all_results;
};