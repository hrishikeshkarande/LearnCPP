#include <iostream> // to allow use of std::cout, std::cin, and std::endl
int main()
{   
    int sum = 0;
    
    int myArray[10];
    for (int i = 0; i<10; i++)
    {
        std::cout << "Enter an integer for element " << i << ": ";
        std::cin >> myArray[i];
    }

    std::cout << "You entered: ";
    for (int i = 0; i<10; i++)
    {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl; 

    for (int i = 0; i<10; i++)
    {
        sum += myArray[i];
    }
    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "The size of the array is: " << sizeof(myArray) << " bytes" << std::endl;

    int size = sizeof(myArray)/sizeof(myArray[0]);
    float avg = (float)sum / (float)size;

    std::cout << "The average is: " << avg << std::endl;
   

    return 0;
}