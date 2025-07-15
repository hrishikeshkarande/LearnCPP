#include <iostream>
#include <vector>
#include <algorithm> // For std::for_each

int main() {
    std::vector<int> data = {10, 20, 30};
    std::string prefix = "Value: "; // Variable from the outer scope

    std::cout << "--- Printing with prefix (by value) ---" << std::endl;
    // Capture 'prefix' by value ([prefix])
    std::for_each(data.begin(), data.end(), [prefix](int n) {
        std::cout << prefix << n << std::endl;
    });

    // Let's change the original prefix
    prefix = "New Value: ";
    std::cout << "\n--- Printing with changed prefix (but lambda saw old one) ---" << std::endl;
    // The lambda above still uses "Value: " because 'prefix' was captured by value (a copy).
    std::for_each(data.begin(), data.end(), [prefix](int n) {
        std::cout << prefix << n << std::endl;
    });


    std::cout << "\n--- Printing with prefix (by reference) ---" << std::endl;
    // Capture 'prefix' by reference ([&prefix])
    // The lambda below will see the *updated* value of 'prefix'.
    std::for_each(data.begin(), data.end(), [&prefix](int n) {
        std::cout << prefix << n << std::endl;
    });

    return 0;
}

/*
Basic Lambda Syntax
The basic syntax of a lambda expression looks like this:

C++

[capture_list](parameters) -> return_type {
    // Function body
}
Let's break down each part:

[capture_list] (The "Capture List"):

This is where you tell the lambda what variables from its surrounding scope it can access.

[]: Empty capture list. The lambda cannot access any variables from the outer scope (only its own parameters or global variables).

[variable_name]: Capture variable_name by value. The lambda gets a copy of the variable at the time the lambda is created. Changes to the original variable after the lambda is created will not affect the captured copy.

[&variable_name]: Capture variable_name by reference. The lambda gets a reference to the original variable. Changes to the original variable will affect what the lambda sees, and the lambda can also modify the original variable.

[=]: Capture all used variables from the surrounding scope by value. (Convenient, but use with caution for large objects).

[&]: Capture all used variables from the surrounding scope by reference. (Convenient, but use with caution to avoid unintended modifications).

You can mix and match, e.g., [=, &myRefVar] (capture all by value, but myRefVar by reference).

(parameters):

This is the parameter list, just like a regular function. It defines the arguments that you pass to the lambda when you call it. Can be empty ().

-> return_type (Optional):

This specifies the return type of the lambda.

If you omit this, the compiler will try to deduce the return type based on what's returned from the body. This is often convenient.

{ body }:

This is the actual code block that the lambda executes, just like a regular function body.
*/