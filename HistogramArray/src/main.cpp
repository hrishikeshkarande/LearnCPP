#include <iostream> // std::cout, std::cin, and std::endl
#include <random>   // rand(), returns a pseudo-random int

int main()
{
    int myArray[17];
    for (int i = 0; i < 17; i++)
    {                               // fill array with random
        myArray[i] = (rand() % 25); // numbers between 0 and 24
        // draw here with std::cout and std::endl
        std::cout << "myArray[" << i << "] = " << myArray[i] << " > ";

        for (int j = 0; j < myArray[i]; j++)
        {
            std::cout << "\u2589";
        }

        std::cout << std::endl; // end of histogram line
        std::cout << std::endl; // for better readability
    }
    return 0;
}
