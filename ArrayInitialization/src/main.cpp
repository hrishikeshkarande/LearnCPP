/**
 Write a program that initializes an array of 50 booleans, repeatedly having two
 elements with a true value, followed by one element with false.
 So the array starts with: true, true, false, true, true, false, true, true, …
 Do not use any variables other than myArray and a loop iteration variable.
*/
#include <iostream>

int main()
{
    bool myArray[50];

    for (int i = 0; i < 50; i++)
    {
        if (i % 3 == 0 || i % 3 == 1)
        {
            myArray[i] = true;
        }
        else
        {
            myArray[i] = false;
        }
    }

    // Optional: Print the array to verify the initialization
    for (int i = 0; i < 50; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            std::cout << std::endl; // New line every 3 elements for better readability
        }
        std::cout << (myArray[i] ? "true " : "false ");
    }

    return 0;
}