#include <iostream>

class Printer {
public:
    Printer() {
        std::cout << "Hello!" << std::endl;
    }
    ~Printer() {
        std::cout << "Goodbye!" << std::endl;
    }
};

int main() {

    Printer obj; // Create an instance of Printer
    // The constructor will be called here, printing "Hello!";
    // The destructor will be called automatically when obj goes out of scope, printing "Goodbye!"  
    return 0; // Return 0 to indicate successful execution
}

// The program will print "Hello!" when the object is created and "Goodbye!" when it is destroyed.
// This demonstrates the use of constructors and destructors in C++.
// The code is compatible with C++20 standards. 