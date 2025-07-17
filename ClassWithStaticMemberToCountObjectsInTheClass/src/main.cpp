#include <iostream>
#include <string>

class Counter
{
public:
    static int count;
    std::string type;

    Counter() : type("void")
    {
        count++;
    }

    Counter(int param) : type("int")
    {
        count++;
    }

    Counter(double param) : type("double")
    {
        count++;
    }

    ~Counter()
    {
        count--;
    }
};

int Counter::count = 0;

int main()
{

    Counter c1, c2(2), c3(3.4);
    std::cout << c1.type << ',' << c2.type << ',' << c3.type << std::endl;
    std::cout << "Current count: " << Counter::count << std::endl;
    return 0;
}

// Output:
// void,int,double
// Current count: 3
// Explanation: The program creates three Counter objects with different constructors,
// each incrementing the static count variable. The types of the objects are printed,
// followed by the current count of Counter objects created.
// The static count variable is shared across all instances of the Counter class.
// The destructor decrements the count when an object is destroyed, but in this case,
// the objects are not destroyed before the program ends, so the count remains 3.
// The program demonstrates the use of static members and constructors in C++.