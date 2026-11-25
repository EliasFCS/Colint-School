#include <iostream>
#include <string>

int multiplication (int a, int b) {
  return a * b;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Error please chose 2 number !" << std::endl;
    return 1;
  } else if (argc > 3) {
    std::cout << "Error please chose 2 number !" << std::endl;
    return 1;
  }

  int a = std::stoi(argv[1]); 
  int b = std::stoi(argv[2]);

  std::cout << a << ' ' << '*' << ' ' << b << ' ' << '=' << ' ' << multiplication(a, b) << std::endl; 
}