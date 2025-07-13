#include <cstdarg>
#include <iostream>

void myPrint(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    while (*format != '\0')
    {
        int i = va_arg(args, int);
        if (*format == 'd')
        {
            std::cout << 'i' << i << ' ';
        }
        else if (*format == 'c')
        {
            std::cout << 'z' << (char)i << ' ';
        }
        ++format;
    }
    va_end(args);
}

int main()
{
    myPrint("dcd", 3, 'a', 14);
    myPrint("cc", 'c', 'd');
    std::cout << '\n';
}