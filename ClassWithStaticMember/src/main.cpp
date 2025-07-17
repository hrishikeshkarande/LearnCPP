#include <iostream>

class Test
{
public:
    static int i;
};

int Test::i;

int main()
{
    Test::i = 77;
    std::cout << "Accessing the static member i without making an object using the class name and colon colon operator as Test::i " << Test::i << std::endl;

    Test t;
    std::cout << "Accessing the class static member from an object t after creating it and then using the dot operator in front of the created object t.i = " << t.i << std::endl;

    return 0;
}

// Output:
// Accessing the static member i without making an object using the class name and colon colon operator as Test::i 77
// Accessing the class static member from an object t after creating it and then using the dot operator in front of the created object t.i = 77
// Note: The output will be the same regardless of whether you use the class name or an object to access the static member, as it is shared across all instances of the class.
// The static member variable is shared across all instances of the class, so it retains its value even when accessed through an object.        