#include <iostream>  // For std::cout
#include <algorithm> // For std::for_each
//#include <iterator>  // For std::begin and std::end (for C-style arrays)

int main() {
    char array[] = {'H', 'e', 'l', 'l', 'o', '?'};

    // Use std::for_each to iterate over the array elements
    // std::begin(array) gives an iterator to the first element
    // std::end(array) gives an iterator to one past the last element
    // The lambda [](char sym) { std::cout << sym << ' '; } is executed for each element
    std::for_each(std::begin(array), std::end(array),
                  [](char sym) { std::cout << sym << ' '; });

    std::cout << '\n'; // Print a newline at the end

    return 0; 
}