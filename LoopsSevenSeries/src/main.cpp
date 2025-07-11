#include <iostream>

int main() {
    float start = 120.0;
    float x = 0;
    std::cout << "Value of x: " << start << std::endl;

    do
    {
        x = start - 7.0;
        std::cout << "Value of x: " << x << std::endl;
        start = x;
    }while(x > 43.7);

    std::cout << "Final value of x: " << start << std::endl;
    std::cout << "Loop ended..." << std::endl;
    
    return 0;
}
