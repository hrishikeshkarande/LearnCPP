#include <iostream>

int main()
{
    int myNumber = 7402312;
    std::cout << "myNumber: " << myNumber << std::endl; // Output: myNumber: 7402312

    int &myPhone = myNumber; // & in this declaration
    // shows that this is a reference. From here on,
    // myNumber and myPhone name the same variable.
    
    std::cout << "myPhone: " << myPhone << std::endl; // Output: myPhone: 7402312

    int myOtherNumber = 2718354;
    std::cout << "myOtherNumber: " << myOtherNumber << std::endl; // Output: myOtherNumber: 2718354


    myPhone = myOtherNumber; // Assigning myOtherNumber to myPhone
    // → Now all three variable names myNumber, myPhone,
    // and myOthernumber, have the same value: 2718354
    // &myPhone = myOtherNumber; is invalid

    std::cout << "myNumber: " << myNumber << std::endl; // Output: myNumber: 2718354
    std::cout << "myPhone: " << myPhone << std::endl; // Output: myPhone: 2718354
    std::cout << "myOtherNumber: " << myOtherNumber << std::endl; // Output: myOtherNumber: 2718354

    return 0;
}


/*
This code demonstrates the use of references in C++.
A reference is an alias for another variable, allowing you to
access and modify the original variable through the reference.
The example shows how changing the value of a reference
affects the original variable and vice versa.
References are declared using the & symbol, and they must be initialized
at the time of declaration. Once a reference is set to a variable,
it cannot be changed to refer to another variable.
References are particularly useful for passing variables to functions
without copying them, thus improving performance and memory usage.
References can also be used to create more readable and maintainable code.
*/