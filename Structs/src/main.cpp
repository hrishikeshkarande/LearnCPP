#include <iostream>
#include <string.h>

struct Key
{
    char label;
    bool pressed;
};

struct Date
{
    int day, month, year;
    std::string season;
};

int main()
{
    //We can create variables of the type stuct similar to invoking objects of a class
    Key item1; 
    item1.label = 'q';
    item1.pressed = false;

    //Below notation of initialization works as well
    Key item2 = {'w',true};

    std::cout << item1.label << " key is " << item1.pressed << std::endl;
    std::cout << item2.label << " key is " << item2.pressed << std::endl;

    //Can also initialize as below

    Date today = {.day = 19, .month = 07, .year = 2025, .season = "Summer"}; //the 0 in 07 of the month does not print

    std::cout << today.day << " " << today.month << " " << today.year << " " << today.season << std::endl;

    //Or can also initialize using the below shorthand

    Date tomorrow = {.day = 20, .month = 07, .year = 2025, .season = "Summer Still"}; //the 0 in 07 of the month does not print

    std::cout << tomorrow.day << " " << tomorrow.month << " " << tomorrow.year << " " << tomorrow.season << std::endl;

    return 0;
}
/*
This program demonstrates the usage of structs in C++. It defines two structs: Key and Date. 
- The Key struct represents a keyboard key with a label (character) and a pressed state (boolean).
- The Date struct represents a calendar date with day, month, year, and season (string).

In the main function:
- Two Key variables are created and initialized using different methods.
- Their values are printed to the console.
- Two Date variables are initialized using designated initializers, showing how to assign values to specific struct members.
- The values of the Date variables are printed to the console.

This program illustrates struct declaration, initialization, and member access in C++.
*/
