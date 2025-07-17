#include <iostream>

class MyClass
{
private:
    bool flag;
    int number;

public:
    MyClass(bool f, int n)
    {
        flag = f;
        number = n;

        printf("Constructor called with flag: %d and number: %d\n", flag, number);
    }

    int get()
    {
        if (flag == true)
        {
            return number;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    int returnValue;
    MyClass myObject(true, 42);
    
    returnValue = myObject.get();

    return returnValue;
}
// This program demonstrates a simple class with a constructor and a method that returns a value based on a condition.
// The main function creates an instance of the class and retrieves a value based on the object's state.
// The program will return 0 since the flag is set to false, which means the get method will return 0.
// The output will also include a message from the constructor indicating the values passed during object creation.
// The program is written in C++20 standard.
// The use of printf is for demonstration purposes; in a real C++ program, you might prefer using std::cout for outputting text to the console.     