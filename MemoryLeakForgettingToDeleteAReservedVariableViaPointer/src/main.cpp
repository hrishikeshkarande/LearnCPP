#include <iostream>

void myfunction(){
    int *myIntPointer = new int; //This newly created variable does not have a name, we can only access it via this pointer
    *myIntPointer = 17; // Assigning a value to the memory location pointed to by myIntPointer
    std::cout << "Value pointed to by myIntPointer: " << *myIntPointer << std::endl;  // Output the value stored at the memory location
}

int main() {
    myfunction();
    //After the above function, myIntPointer gets removed from memory, but not the variable
    //We can no longer access it
    // However, we can delete it to free up memory
    // Note: In this example, we do not delete myIntPointer as it is not accessible outside myfunction.
    // In a real application, you should always delete dynamically allocated memory to avoid memory leaks.
    return 0;
}

// This code demonstrates the use of dynamic memory allocation in C++ using pointers.
// It shows how to create a pointer to an integer, assign a value to it, and print that value.
// The pointer is created using the 'new' operator, which allocates memory on the heap.
// Remember to manage memory properly in real applications to avoid leaks.
// The code is written in C++20 standard, which allows for modern features and better memory management practices.