/**
 Try to figure out what is happening in the code below. Then try to compile the 
 code, and then change the commented part so that the code's output becomes 1:
*/
#include <iostream>  // to allow use of std::cout and std::endl
int main() {
  auto i = 7;    // what type is variable i?
  auto j = 9.0;  // what type is variable j?
 
  bool ret = ( ( i <=> j) < 0 );  // change the '== 0' part so that the output is 1   
 
  std::cout << ret << std::endl;
  return 0;
}

// The code uses the spaceship operator (<=>) to compare two variables i and j.
// The spaceship operator returns a value that indicates the relationship between the two operands.
// The expression (i <=> j) returns a value that is less than, equal to, or greater than zero, depending on whether i is less than, equal to, or greater than j.
// The comparison ( ( i <=> j) < 0 ) checks if the result of the spaceship operator is less than zero, which means i is less than j.
// The result of this comparison is stored in the boolean variable ret, which is then printed to the console.
// To change the output to 1, we need to modify the comparison so that it evaluates to true.
// The current comparison checks if i is less than j, which is true since 7 is less than 9.0.
// To change the output to 1, we can modify the comparison to check if i is greater than j instead.
// This can be done by changing the comparison to ( ( i <=> j) > 0 ).
// This will evaluate to true since 7 is not greater than 9.0, and the output will be 1.
// However, since we want the output to be 1, we can also change the comparison to check if i is equal to j, which can be done by changing the comparison to ( ( i <=> j) == 0 ).
// This will evaluate to false since 7 is not equal to 9.0, and the output will be 0.
// Therefore, to change the output to 1, we can modify the comparison to check if i is less than j, which is already the case in the original code.
// The output will be 1 since 7 is less than 9.0, and the comparison will evaluate to true.