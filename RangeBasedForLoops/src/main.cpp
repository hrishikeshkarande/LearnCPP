#include <iostream> // output to the console
int main()
{
    int array[] = {8, 2, 7, 2, 8, 7, 9, 1};
    for (auto value : array)
    { // foreach loop over array
        std::cout << value << ' ';
    }
    std::cout << '\n';
}