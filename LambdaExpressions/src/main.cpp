#include <iostream> // output to the console
int main()
{
    int a = 7, b = 14;
    // passing a and b by reference:
    auto swap = [&a, &b]()  { int t = a; a = b; b = t; };
    
    // Note that this won't work:
    // auto swap = [a, b]() { int t = a; a = b; b = t; };
    
    swap();
    
    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
}


/*
That's a very insightful question, and it gets to the heart of how lambda expressions work in C++\! You are absolutely right: `auto swap` declares a variable. The key to understanding this lies in how the C++ compiler treats lambda expressions.

Here's the breakdown:

1.  **Lambdas are "Function Objects" (Functors):**
    When you write a lambda expression (e.g., `[&a, &b]() { int t = a; a = b; b = t; }`), the C++ compiler doesn't just create an anonymous function in the traditional sense. Instead, it **implicitly generates a unique, unnamed class type** behind the scenes.

    This generated class has:

      * A way to store any variables you "capture" (like `a` and `b` in your example).
      * An **overloaded `operator()`** (the "call operator"). This is what makes objects of this class callable like functions.

2.  **`auto swap = ...;` Declares an Object:**
    When you write `auto swap = ...;`, you are indeed declaring a variable named `swap`.

      * The `auto` keyword tells the compiler to deduce the type of `swap`.
      * The type that the compiler deduces is that **unique, unnamed class type** it generated for your lambda expression.
      * So, `swap` is not a function itself; it's an **object (an instance)** of that compiler-generated class.

3.  **`swap();` Calls the `operator()` on the Object:**
    When you then write `swap();`, you are not directly calling an unnamed function. Instead, you are invoking the **`operator()`** of the `swap` object. Because the compiler has defined `operator()` for that generated class, objects of that class can be used with function-call syntax.

**Analogy:**

Imagine you manually wrote a class like this (simplified):

```cpp
// This is conceptually what the compiler does for your lambda
class MySwapLambdaType {
private:
    int& captured_a; // Stores a reference to the original 'a'
    int& captured_b; // Stores a reference to the original 'b'

public:
    // Constructor to store the references when the object is created
    MySwapLambdaType(int& a_ref, int& b_ref) : captured_a(a_ref), captured_b(b_ref) {}

    // Overload the function call operator '()'
    // This makes objects of MySwapLambdaType callable like functions
    void operator()() const { // 'const' because it doesn't modify its own members
        int t = captured_a;
        captured_a = captured_b;
        captured_b = t;
    }
};

int main() {
    int x = 7, y = 14;

    // Declaring a variable 'my_swap_obj' of our custom type
    // We pass 'x' and 'y' by reference to its constructor, just like [&a, &b] captures
    MySwapLambdaType my_swap_obj(x, y);

    // Calling the 'operator()' method on the 'my_swap_obj' object
    my_swap_obj(); // This looks exactly like a function call!

    std::cout << "x = " << x << '\n'; // Will be 14
    std::cout << "y = " << y << '\n'; // Will be 7
}
```

**In summary:**

The lambda expression is a convenient syntax for the compiler to automatically create this anonymous class and its `operator()`. When you assign the lambda to a variable (like `swap`), that variable becomes an **object** of this anonymous class. Calling `swap()` then simply invokes the `operator()` of that `swap` object.

This design makes lambdas incredibly powerful for passing around small pieces of functionality, especially when they need to "capture" variables from their surrounding context.
*/