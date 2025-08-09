#include <iostream>

int main() {
    int myInteger = 17;
    const int constInt = 71;

    int const * ptrToConstInt = &constInt; //This is a pointer to the constant integer
    int * const constPtrToInt = &myInteger; //This is a constant pointer to the normal integer
    int const * const constPtrToConstInt = &constInt; //This is a constant integer pointer to the constant integer
    const int * ptrToConstInt2 = &constInt; //This is same as the first pointer

    /*

    //You can check the compliation error that arises from trying to change these different types of constant pointer by observing the red underline after uncommenting

    *ptrToConstInt = myInteger; //This will cause a compilation error because ptrToConstInt points to a constant integer
    constPtrToInt = &myInteger; //This will cause a compilation error because constPtrToInt is a constant pointer
    *constPtrToConstInt = myInteger; //This will cause a compilation error because constPtrToConstInt points to a constant integer
    constPtrToConstInt = &myInteger; // This will also cause a compilation error because constPtrToConstInt is a constant pointer
    
    */

    return 0;    
}

// This code demonstrates the use of pointers to constant integers and constant pointers in C++.
// It shows how to declare and use pointers that point to constant integers and constant pointers,
// as well as the compilation errors that arise when trying to modify them.
// The code is written in C++20 standard and is intended to be compiled with a C++ compiler that supports this standard.
// The comments in the code explain the purpose of each pointer and the expected errors when trying to modify them.