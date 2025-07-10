#include <iostream>

int main() {
    char mysymbol;
    
    mysymbol = 'a';
    std::cout << mysymbol << '\n';
    
    mysymbol = 'q';
    std::cout << mysymbol << '\n';
    
    std::cin.get();
    return 0;
}
// This code prints two characters, 'a' and 'q', each followed by a newline character.
// The first character is assigned to the variable mysymbol, which is then printed.
// The second character is assigned to the same variable, overwriting the first value, and printed again.
// The output will be:
// a
// q
// This demonstrates the use of character variables in C++ and how they can be reassigned.
// The code is written in C++20, which supports modern features and syntax improvements.
// The program includes the iostream library for input and output operations.
// The main function serves as the entry point of the program, where execution begins.
// The use of std::cout allows for printing to the standard output, and '\n'
// is used to insert a newline after each character output.
// The program returns 0 at the end, indicating successful execution.
// The code is simple and straightforward, showcasing basic variable assignment and output in C++.