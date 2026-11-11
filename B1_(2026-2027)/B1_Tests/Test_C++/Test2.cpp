// Addition of 2 params with a function.

#include <iostream>  // For std::cout and std::endl.
#include <string>  // For std::stoi.


int addition(int a, int b) {  // Function that process an addition with 2 params.    
    return a + b;  // Return The result, that define the function into the result, so we can print the result by printing the function.
} // End of the addition function.



int main(int argc, char* argv[]) {  // Main Zone.

    if (argc < 3) {  // Check if the number of arguments is '3'. Example: " ./Test 1  3 ".

        std::cout << "Error: Please choose only 2 numbers !" << '\n' << "Example: ./Test 1  3" << std::endl; // Print a custom error message.

        return 1; // Optimisation.


    } else if (argc > 3) {  // Check if the number of arguments is '3'. Example: " ./Test 1  3 ".

        std::cout << "Error: Please choose only 2 numbers !" << '\n' << "Example: ./Test 1  3" << std::endl; // Print a custom error message.

        return 1; // Optimisation.
    }



    // Arguments config: Argv[0] is the ./Executable.  And it is the "First" Argument.
    int a = std::stoi(argv[1]); // Argv[1] is the 'a' param of the function addition And it is the "Second" Argument.
    int b = std::stoi(argv[2]); // Argv[2] is the 'b' param of the function addition And it is the "Third" Argument.
    // The Textual Arguments are converted into integer.


    // Print the operation with param a and b, it print also the result by printing the function addition. 
    std::cout << a << ' ' << '+' << ' ' << b << ' ' << '=' << ' ' << addition(a, b) << std::endl; 

    return 0; // Optimisation.
}