#include <iostream>

int main (void) {


  // Declaration and definition of variables.
  int integer = 4;  // First integer.
  int integer2 = 36; // Second integer.
  double float2 = 12.43; // Double type.
  char letter = 'E'; // A character.
  const char* string = "Test"; // A string of characters.
  bool YN = true; // Boolean Variable


  int addition = integer + integer;  // 4 + 4 = 8. (addition)   
  float substraction = float2 - integer;   // 12.43 - 4 = 8.43. (substraction)
  int multiplication = integer * integer;  // 4 * 4 = 16. (multiplication)
  int division = integer2 / integer;  // 36 / 4 = 9. (Division)
  float stay = integer2 % integer;   // 36 % 4 = 0.  (Stay)


  // Print all the results of variables manipulations/operations.
  std::cout << "The result of the addition is:" << ' ' << addition << '\n' << "The result of the substraction is:" << ' ' << substraction << '\n' << "The result of the multiplication is:" << ' ' << multiplication << '\n' << "The result of the division is:" << ' ' << division << ' ' << "And the stay is:" << ' ' << stay << '\n' << "Example of Letter:" << ' ' << letter << ' ' << "And a Example of string:" << ' ' << string << '\n' << "The state of the variable YN is:" << ' ' << YN << std::endl;

  return 0;
}