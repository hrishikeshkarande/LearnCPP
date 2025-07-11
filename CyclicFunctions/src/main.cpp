#include <iostream>
int a(); // Forward declaration of function a
int b(); // Forward declaration of function b

int a(){ // Definition of function a
    std::cout << "Yes" << std::endl;
    return b();
}

int b(){ // Definition of function b
    std::cout << "No" << std::endl;
    return a();
}

int main()
{       
        a(); // Call function a to start the recursion
        std::cout << "back" << std::endl;

    return 0;
}