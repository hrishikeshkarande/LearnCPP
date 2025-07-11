#include <iostream>

int main() {
    float num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    while (num >= 10){
        std::cout << num << std::endl;
        num = num / 2;

    }    
    
}