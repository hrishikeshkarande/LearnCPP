#include <iostream>
#include <string>

// Function to add two integers
int add(int a, int b) {
    std::cout << "Calling add(int, int): ";
    return a + b;
}

// Overloaded function to add two doubles
double add(double a, double b) {
    std::cout << "Calling add(double, double): ";
    return a + b;
}

// Overloaded function to concatenate two strings
std::string add(std::string s1, std::string s2) {
    std::cout << "Calling add(string, string): ";
    return s1 + s2;
}

// Overloaded function to add three integers
int add(int a, int b, int c) {
    std::cout << "Calling add(int, int, int): ";
    return a + b + c;
}

int main() {
    int sum1 = add(5, 3);
    std::cout << "Result: " << sum1 << std::endl;

    double sum2 = add(10.5, 2.3);
    std::cout << "Result: " << sum2 << std::endl;

    std::string combined = add("Hello, ", "World!");
    std::cout << "Result: " << combined << std::endl;

    int sum3 = add(1, 2, 3);
    std::cout << "Result: " << sum3 << std::endl;

    return 0;
}