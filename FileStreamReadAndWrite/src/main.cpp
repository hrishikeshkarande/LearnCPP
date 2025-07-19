#include <iostream>
#include <fstream> // in/output file stream classes 


int main() {
    std::ifstream myfile("TestFile.txt"); //initialize the input file using the class constructor giving the file name
    std::ofstream myfilecopy("SecondTestFile.txt"); //initialize the output file using the class constructor giving the file name

    auto c = ' ';
    // get each character from input file stream and output to output file stream

    while(myfile.get(c)) {
        myfilecopy << c;
    }

    std::cout << "File Contents Copied" << std::endl;

    return 0;

}