#include <iostream> // for std::cout and tuples functionality 

auto arithmetic(int a, int b){
    return std::make_tuple(a + b, a - b, a * b, a / b);
}

int main() {
    auto myData = std::make_tuple("Hrishikesh","Karande",176.5); 

    // get with index-based access:
    std::cout << std::get<0>(myData) << " " << std::get<1>(myData) << " " << std::get<2>(myData) << "\n";

    //get with type-based access:
    std::cout << std::get<double>(myData) << "\n"; //(works only if 1 tuple element has this type, otherwise the compiler reports an error)

    //Unpack the contents of the tuple:
    auto [fname,lname,height] = myData;

    std::cout << "After unpacking..." << "\n" << fname << "\n" << lname << "\n" << height << "\n";

    //One More Example
    auto arith = arithmetic(2,5);

    std::cout << "Addition is: " << std::get<0>(arith) << "\n";
    std::cout << "Subtraction is: " << std::get<1>(arith) << "\n";
    std::cout << "Multiplication is: " << std::get<2>(arith) << "\n";
    std::cout << "Division is: " << std::get<3>(arith) << "\n";

    //Even the below is possible 
    auto [add, sub, mul, div] = arithmetic(5, 7);
    std::cout << "After unpacking Add is: " << add << "\n";
    std::cout << "After unpacking Sub is: " << sub << "\n";
    std::cout << "After unpacking Mul is: " << mul << "\n";
    std::cout << "After unpacking Div: " << div << "\n";


    return 0;
}


/**
 * tuple_example
 * This program demonstrates the usage of `std::tuple` in C++, a versatile way to group different types of values.
 *
 * In C++, a `std::tuple` (pronounced "too-pull") is like a very flexible container that can hold a fixed number
 * of values, where each value can be of a completely different data type.
 *
 * Think of it like a temporary mini-structure or mini-class where you don't need to define a formal name
 * for its members. It's especially useful for situations where you want a function to return multiple
 * different types of values, or when you just need to group a few related pieces of information together
 * without creating a whole new `struct` or `class` definition.
 *
 * This program demonstrates:
 *
 * 1.  **Creating a Tuple:**
 * - We use `std::make_tuple()` to easily create a tuple. You simply provide the values, and C++
 * automatically figures out the types of each element and creates the tuple for you.
 * Example: `std::make_tuple("Hrishikesh","Karande",176.5)` creates a tuple holding a string, another string, and a floating-point number.
 *
 * 2.  **Accessing Elements by Index:**
 * - You can get individual values from a tuple using `std::get<INDEX>(tuple_variable)`.
 * - The `INDEX` is a number (starting from 0 for the first element, 1 for the second, and so on).
 * - This method always works, as each element has a unique index.
 * - Example: `std::get<0>(myData)` gets the first element.
 *
 * 3.  **Accessing Elements by Type (with caution!):**
 * - You can also try to get a value using `std::get<TYPE>(tuple_variable)`.
 * - **Important Rule:** This only works if there is *exactly one* element of that specific `TYPE` in your tuple.
 * If your tuple has, for example, two `int`s, and you try `std::get<int>(myTuple)`, the compiler will
 * report an error because it doesn't know which `int` you want. If there's only one `double`,
 * `std::get<double>(myTuple)` will work.
 *
 * 4.  **Unpacking Tuples (Structured Bindings - C++17 Feature):**
 * - This is a very convenient and modern (C++17 and later) way to extract all the contents of a tuple
 * into individual, named variables in one line.
 * - Syntax: `auto [variable1, variable2, ...] = tuple_variable;`
 * - This makes your code much cleaner and easier to read when you receive a tuple.
 * - Example: `auto [fname,lname,height] = myData;` directly creates `fname`, `lname`, and `height` variables
 * and assigns the corresponding tuple elements to them.
 *
 * 5.  **Returning Tuples from Functions:**
 * - Functions can be designed to return `std::tuple`s. This is an excellent way for a function to
 * "return" multiple pieces of related information, which is something standard functions normally
 * cannot do directly (they can only return one value).
 * - The `arithmetic` function in this example calculates addition, subtraction, multiplication, and division
 * and returns all four results wrapped in a single `std::tuple`.
 *
 * By understanding `std::tuple`, you gain a flexible tool for handling grouped data, especially when
 * dealing with functions that produce multiple results or for temporary data structures.
 */