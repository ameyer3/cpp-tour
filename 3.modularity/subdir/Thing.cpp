#include "Thing.h"

Thing createThing(std::string name, int value)
{
    return {name, value};
}
void fillMap(std::map<std::string, int> &m)
{
    // i shouldve just done `using namespace std;`
    m.insert(std::pair<std::string, int>("one", 1));
    m.insert(std::pair<std::string, int>("two", 2));
}
