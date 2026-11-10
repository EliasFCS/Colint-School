#include <iostream>

int main (void) {

  int integer = 4;
  int integer2 = 36;
  double float2 = 12.43;
  char letter = 'E';
  const char* string = "Test";
  bool YN = true;


  int addition = integer + integer;  // 4 + 4 = 8.    
  float substraction = float2 - integer;   // 12.43 - 4 = 8.43.
  int multiplication = integer * integer;  // 4 * 4 = 16.
  int division = integer2 / integer;  // 36 / 4 = 9. 
  float stay = integer2 % integer;   // 36 % 4 = 0. 

  std::cout << "The result of the addition is:" << ' ' << addition << std::endl;
  std::cout << "The result of the substraction is:" << ' ' << substraction << std::endl;
  std::cout << "The result of the multiplication is:" << ' ' << multiplication << std::endl;
  std::cout << "The result of the division is:" << ' ' << division << ' ' << "And the stay is:" << ' ' << stay << std::endl;
  std::cout << "Example of Letter:" << ' ' << letter << ' ' << "And a Example of string:" << ' ' << string << std::endl;
  std::cout << "The state of the variable YN is:" << ' ' << YN << std::endl;
  
  return 0;
}