#include <iostream>

int main() {
    int num = 131;
    while (num >= 23){
        std::cout << num << std::endl;
        if (num % 7 == 0){
            std::cout << "hop" << std::endl;
        }
        num -= 1;
    }
    return 0;
}