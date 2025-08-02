#include <iostream>

int main() {
    char myName[4] = "Rao";
    char * charpointer = NULL;
    charpointer = myName; //Here myName us same as &myName[0], i.e myName == &myName[0], it is the address of first element  

    std::cout << "1st: " << *(charpointer) << std::endl; //

    std::cout << "2nd: " << myName[1] << std::endl; //This will print 'a' which is the 2nd element in the array

    std::cout << "3rd: " << *(charpointer + 2) << std::endl; //This will print 'o' which is the 3rd element in the array
 
    std::cout << "4th: " << *(charpointer + 3) << std::endl; //This will print Null character

    std::cout << "5th: " << *(charpointer + 4) << std::endl; //This will also print garbage value as it is out of bounds

    std::cout << "6th: " << *(charpointer + 5) << std::endl; //This will also print garbage value as it is out of bounds
    
    return 0;
}