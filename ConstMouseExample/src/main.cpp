#include <iostream>


/** Print a mouse in the console, using a const pointer to avoid changes */
[[nodiscard]] auto * getBitmapAddress(){
    static const char bitmap[] = "(^._.^)~\n"; //bitmap is a character array created in the static memory
    return bitmap; //return pointer to the first element
}

int main() {
    auto * mousePointer = getBitmapAddress(); //This is a normal pointer to the first element of the bitmap array
    while (*mousePointer != 0) {
        std::cout << *(mousePointer++);
    }
    // Output: (^._.^)~

    //What is the pointer holding now?
    std::cout << "\nPointer now holds: " << static_cast<const void *>(mousePointer) << "\n";
    //Has the pointer changed?
    std::cout << "Pointer has changed: " << (mousePointer != getBitmapAddress()) << "\n";

    //If you remove the second const below you will observe that the pointer can be changed, we dont want that because this is a bitmap
    auto const * const safemousepointer = getBitmapAddress(); //This is a const pointer to the first element of the bitmap array

    auto temppointer = safemousepointer; //We declare a temporary pointer to the same address for printing

    while (*temppointer != 0) {
        std::cout << *(temppointer++);
    }

    //Now the temporary pointer would have changed but out safemousepointer remains the same

    //Has the new pointer changed?
    std::cout << "\nNew pointer has changed: " << (safemousepointer != getBitmapAddress()) << "\n";

    //Try to change the safemousepointer
    //safemousepointer++; //This line would cause a compilation error because safemousepointer is a const pointer

    //Has the new pointer changed?
    std::cout << "\nNew pointer has changed: " << (safemousepointer != getBitmapAddress()) << "\n";
    return 0;
}