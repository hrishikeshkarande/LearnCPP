#include <iostream>

void swapbyvalue(int x, int y)
{ // This does not work as the local variables of this function do not get passed to the main.
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

void swapbyrefuntidy(int *x, int *y)
{ // This looks dirty but you have seen this before and actually this is so much clear and deep.
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapbyref(int &x, int &y)
{   // & in this declaration shows that this is a reference.
    // From here on, a and x are names of the same variable. Alias! Same for b and y! This is different than pointer slightly.
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 5, b = 10;

    swapbyvalue(a, b);

    std::cout << "Value of a: " << a << " Value of b: " << b << std::endl;

    swapbyrefuntidy(&a, &b);

    std::cout << "Value of a: " << a << " Value of b: " << b << std::endl;

    swapbyref(a, b);

    std::cout << "Value of a: " << a << " Value of b: " << b << std::endl;

    return 0;
}


/*
This code demonstrates three different methods of swapping two integers in C++:
1. `swapbyvalue`: Swaps values but does not affect the original variables.
2. `swapbyrefuntidy`: Uses pointers to swap values, which is less clean
   but effective.
3. `swapbyref`: Uses references to swap values, which is clean and effective.
The output shows the values of `a` and `b` after each swap attempt.
This code is written in C++20.
It illustrates the differences between passing by value, passing by pointer, and passing by reference.
*/