#include <iostream>
#include <cstdarg> // Required for va_list, va_start, va_arg, va_end
#include <string>

// Function that sums a variable number of integers
// The first argument 'count' tells us how many integers follow.
double sum_numbers(int count, ...) {
    va_list args;      // Declare a va_list variable
    double total = 0.0;

    va_start(args, count); // Initialize args, telling it that 'count' is the last fixed arg

    for (int i = 0; i < count; ++i) {
        // Retrieve each argument as a double
        // IMPORTANT: If you pass an int but retrieve as double, it works due to promotion.
        // If you pass a float, it's promoted to double.
        // If you pass a long long and retrieve as double, it's fine.
        // But if you pass a string literal and retrieve as double, it's undefined behavior!
        total += va_arg(args, double);
    }

    va_end(args);      // Clean up the va_list
    return total;
}

// A printf-like function (simplified)
void log_message(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            switch (*(++format)) {
                case 'd': // Integer
                    std::cout << va_arg(args, int);
                    break;
                case 'f': // Double (float is promoted to double)
                    std::cout << va_arg(args, double);
                    break;
                case 's': // C-style string (char*)
                    std::cout << va_arg(args, const char*);
                    break;
                default:
                    std::cout << *format; // Print the character itself
            }
        } else {
            std::cout << *format; // Print regular characters
        }
        ++format;
    }
    std::cout << std::endl;

    va_end(args);
}

int main() {
    std::cout << "Sum 1: " << sum_numbers(3, 10.0, 20.5, 5.0) << std::endl;
    std::cout << "Sum 2: " << sum_numbers(2, 7.5, 2.5) << std::endl;

    log_message("My age is %d and my height is %f meters.", 30, 1.75);
    log_message("Hello, %s!", "World");
    log_message("Just a simple message.");

    return 0;
}