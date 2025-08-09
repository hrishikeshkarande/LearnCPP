#include <iostream>
#include <functional>
#include <stdexcept>

class NumberSequence {
public:
    NumberSequence(int length = 10);
    ~NumberSequence(); // Destructor to prevent memory leaks
    void forEach(std::function<int(int)> func);
    void print() const;
private:
    const int length;
    int* seq;
};

// Define all NumberSequence methods
NumberSequence::NumberSequence(int length)
    : length(length) {
    if (length < 0) {
        throw std::invalid_argument("Length must be non-negative");
    }
    seq = new int[length];
    for (int i = 0; i < length; ++i) {
        seq[i] = i;
    }
}

NumberSequence::~NumberSequence() {
    delete[] seq; // Free the dynamically allocated memory
}

void NumberSequence::forEach(std::function<int(int)> func) {
    for (int i = 0; i < length; ++i) {
        seq[i] = func(seq[i]);
    }
}

void NumberSequence::print() const {
    std::cout << "Sequence: ";
    for (int i = 0; i < length; ++i) {
        std::cout << seq[i] << " ";
    }
    std::cout << "\n";
}

int times2(int n) { return n * 2; }

int main() {
    NumberSequence s;
    s.print();
    s.forEach(&times2);
    s.print();
    return 0;
}