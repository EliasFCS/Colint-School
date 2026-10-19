int my_recursive_factorial(int param_1)
{
    if (param_1 < 0) return 0;

   for (int i = 1; i <= param_1; i++) {
    param_1 *= i; 
   }
   return param_1;
}


/*
**
** QWASAR.IO -- my_recursive_factorial
**
** @param {int} param_1
**
** @return {int}
**



Let’s create a function to calculate the factorial of a number!

Create a function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.

If there’s an error, the function should return 0. You have to use the recursive method to perform this exercise. While / for / any loop are forbidden.



🧪 TESTS TO CONSIDER
INPUT 2
EXPECTED RETURN 2
INPUT 3
EXPECTED RETURN 6
INPUT -1 (negative)
EXPECTED RETURN 0
INPUT 0
EXPECTED RETURN Check your own reading of the subject

*/
