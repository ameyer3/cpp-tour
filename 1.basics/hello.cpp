#include <iostream>
#include <vector>

const auto ARRAY_LENGTH = 6;
constexpr int sum(int a, int b)
{
    return a + b;
}

void intLiteralTests();
int sumOfArrayManuallyForeach(int (&arr)[ARRAY_LENGTH]);
int sumOfArrayManuallyFor(int arr[]);
void doVectorStuffNoChange(const std::vector<int> &);
void doVectorStuffChange(std::vector<int> &);
void somePointerAndReferenceThings();
int someLogic(int *);
void checkResult(int);

int main()
{
    std::cout << "Helloo";
    // vars, pointers, functions
    auto val = sum(2, 3);
    int *p = &val;
    std::cout << "The adress is this: " << p << " and the value is this " << *p << "\n";

    intLiteralTests();

    // array things
    // conclusion here: never use a C array again
    int arr[]{1, 2, 3, 4, 5, 6};
    std::cout << "Sum of our array is: " << sumOfArrayManuallyForeach(arr) << "\n";
    std::cout << "Sum of our array but different is: " << sumOfArrayManuallyFor(arr) << "\n";

    // vector
    std::cout << "Now some fun vector stuff:\n";
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    doVectorStuffNoChange(v);
    doVectorStuffChange(v);
    doVectorStuffNoChange(v);

    somePointerAndReferenceThings();

    int a = 3;
    int *p1 = nullptr;
    int *p2 = &a;
    checkResult(someLogic(p2));
    checkResult(someLogic(p1));
}

void intLiteralTests()
{
    int p{0b10010};
    int longInt{1'000'000'000};
    std::cout << "P is now going to be a decimal: " << p << "\n";
    std::cout << longInt << "\n";
}

// bc it is not an array due to old people reasons
// so pass it by reference to keep all infos
int sumOfArrayManuallyForeach(int (&arr)[ARRAY_LENGTH])
{
    int sum{0};
    for (auto &x : arr)
    {
        sum += x;
    }
    return sum;
}

int sumOfArrayManuallyFor(int arr[])
{
    int sum{0};
    for (auto i = 0; i < ARRAY_LENGTH; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

// i am not giving a copy but a reference of my vec
void doVectorStuffNoChange(const std::vector<int> &v)
{
    // I am not allowed to change it like that
    // v[2] = 3;

    // I use the reference to each element instead of copying it into a new variable each time
    for (auto &x : v)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
void doVectorStuffChange(std::vector<int> &v)
{
    v[2] = 89;
}

void somePointerAndReferenceThings()
{
    int a = 2;
    int b = 3;
    int z = 4;
    int y = 5;
    // this is a pointer
    int *pa = &a;
    int *pb = &b;
    std::cout << "\n"
              << "Value: "
              << *pa << " Adress: " << pa;
    // they now point to the same thing
    pa = pb;
    std::cout << "\n"
              << "Value: "
              << *pa << " Adress: " << pa;
    // this is a reference
    int &ra = a;
    int &rb = b;
    std::cout << "\n"
              << "Value: "
              << rb << " Adress: " << &rb;
    // the value of the thing being referenced changes, not the refrence/address
    rb = ra;
    std::cout << "\n"
              << "Value: "
              << rb << " Adress: " << &rb;
}

int someLogic(int *ptr)
{
    int input;

    // if not nullptr
    if (ptr)
    {
        std::cout << "What do you want, 1, 2 or 3?";
        std::cin >> input;
    }
    else
    {
        input = 0;
    }

    switch (input)
    {
    case 0:
        return -1;
    case 1:
    case 2:
        return 1;
    case 3:
        return 2;
    default:
        return 0;
    }
}

void checkResult(int result)
{
    // if not 0
    if (result)
    {
        std::cout << "Looks good!";
    }
    else
    {
        std::cout << "Eh";
    }
}