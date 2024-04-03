#include <iostream>
#include <map>
struct Thing
{
    std::string name;
    int value;
};
void fillMap(std::map<std::string, int> &m);
Thing createThing(std::string name, int value);