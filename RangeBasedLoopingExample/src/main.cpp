#include <iostream> // output to the console with std::cout
#include <iomanip> // Required for std::setw and std::setfill


int main() {
    int myarray[7][7];
    
    int count = 0;

    for (auto & row : myarray) {
        for (auto & col : row) {
            col = ++count;
        }
    }
    for (auto & row : myarray) {
        for (auto & col : row) {
            std::cout << std::setw(2) << std::setfill('0') << col << " ";
        }
        std::cout << std::endl;
    }


}