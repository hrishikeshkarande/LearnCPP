#include <iostream>

int main() {
    int myInteger = 12; 
    //This statement stores the value 12 in a variable of type int which is called myInteger

    std::cout << "Value stored in the myInteger variable: " << myInteger << std::endl; 
    //This will print the value of myInteger, which is 12

    int * myIntPointer; 
    //This statement declares a pointer variable of type int called myIntPointer

    std::cout << "Pointer myIntPointer currently uninitilized and is holding the garbage value: " << myIntPointer << std::endl; 
    //This will print the address that myIntPointer is currently pointing to, which is uninitialized at this point

    myIntPointer = NULL; 
    //This statement initializes myIntPointer to NULL, indicating that it currently points to no valid memory location

    std::cout << "Pointer myIntPointer currently still uninitilized but assigned NULL: " << myIntPointer << std::endl; 
    //This will print the address that myIntPointer is currently pointing to, which is uninitialized at this point

    myIntPointer = &myInteger; 
    //This statement assigns the address of myInteger to myIntPointer

    std::cout << "The address of the myInteger variable is: " << &myInteger << std::endl;
    //This will print the address of myInteger, which is where the value 12 is stored in memory

    std::cout << "The pointer myIntPointer has been initialized and now holds: " << myIntPointer << std::endl; 
    //This will print the address of myInteger, which is now stored in myIntPointer

    std::cout << "Let us also check the own address of the pointer variable myIntPointer: " << &myIntPointer <<std::endl;
    //This will print the address of the pointer variable itself, which is where myIntPointer is stored in memory

    *myIntPointer = 17; 
    //This statement dereferences myIntPointer and assigns the value 17 to the location it points to, effectively changing myInteger's value

    std::cout << "The changed value of the variable myInteger after derefrencing: " << myInteger << std::endl;
    //This will print the new value of myInteger, which is now 17

    std::cout << "The address of the variable myInteger after derefrencing: " << &myInteger << " The address of the Pointer myIntPointer after defrefrencing: " << &myIntPointer << std::endl;
    // This will print the address of myIntPointer and the address of myInteger, which should be unchanged even after the derefrencing operation

    return 0;
}

/*
This code demonstrates the use of pointers in C++. 
It initializes an integer variable, creates a pointer to that variable, and shows how to manipulate the value through the pointer. 
The code also prints out addresses and values at various stages to illustrate how pointers work in C++.
This code is written in C++20 and uses standard input/output libraries.
*/