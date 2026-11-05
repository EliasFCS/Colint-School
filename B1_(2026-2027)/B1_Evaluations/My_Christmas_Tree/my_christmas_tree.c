#include <stdio.h>
#include <stdlib.h>

void my_christmas_tree(int size) {      
    if (size <= 0) { 
        return; 
    } 


int main(int ac, char **av) { 
    if (ac != 2) {
        return 0;
    }

    int size = atoi(av[1]);

    my_christmas_tree(size); 
    return 0;
}

// Commande de compilation:  gcc -Wall -Wextra -Werror my_christmas_tree.c -o my_christmas_tree




/*

Submit directory: ex00 Submit file: my_christmas_tree.c

Create a program which can be run in the terminal that displays a Christmas Tree.

Size will be given as the first parameter of the program.

Usage: ./my_christmas_tree <size>

Example 00:

$>./my_christmas_tree 0
$>
Example 01:

$>./my_christmas_tree 1
   *
  ***
 *****
*******
   |
Example 02:

$>./my_christmas_tree 5
                   *
                  ***
                 *****
                *******
                 *****
                *******
               *********
              ***********
             *************
              ***********
             *************
            ***************
           *****************
          *******************
         *********************
           *****************
          *******************
         *********************
        ***********************
       *************************
      ***************************
     *****************************
       *************************
      ***************************
     *****************************
    *******************************
   *********************************
  ***********************************
 *************************************
***************************************
                 |||||
                 |||||
                 |||||
                 |||||
                 |||||
$>
Ressource
From docode you can download qwasar_my_christmas_tree by executing this command:

curl -s https://storage.googleapis.com/qwasar-public/qwasar_my_christmas_tree.tgz | tar zxvf - -C ./
🧪 Test ideas to consider — My Christmas Tree
Input 0
Expected Output (nothing, empty output)
Input 1
Expected Output 1-tier tree + a single-line "|" trunk (see subject example)
Input 5
Expected Output Full 5-tier tree + a 5-line "|||||" trunk (see subject example)
Input Negative number
Expected Output Behavior to define, but must not segfault or loop forever
Input Check the alignment of each line
Expected Output The number of spaces before the '*' must correctly center the tree relative to its base
Input Check the trunk
Expected Output The number of '|||||' lines in the trunk must match the given size parameter exactly

*/