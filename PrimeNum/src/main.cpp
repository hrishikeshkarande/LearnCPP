#include <iostream>

int main() {

    for (int num = 3; num <= 99; num++) {
        
        for(int i = 2; i < num; i++) {
            if (num % i == 0) {
                goto label; // Using goto to skip to the label if num is not prime
            }
        }

        std::cout << num << " is a prime number." << std::endl;

    label:; //comes from the goto statement
    }
    return 0;
}