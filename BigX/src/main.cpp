#include <iostream>

int main() {
    int size;
    std::cin >> size;

    for (int row = 0; row < size; row++){
        for (int col = 0; col < size; col++) {
            if (row == col || row + col == size - 1) {
                std::cout << "X";
            } 
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}