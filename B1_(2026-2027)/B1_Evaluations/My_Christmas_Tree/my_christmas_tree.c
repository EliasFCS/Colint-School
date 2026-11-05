#include <stdio.h>
#include <stdlib.h>

void my_christmas_tree(int size) {      
    if (size <= 0) { 
        return; 
    } 

   int max_width = 6 * size + 1;
   int base_start_width = 1;

   for (int t = 0; t < size; t++) {
    int num_rows = t + 4;
    int current_width = base_start_width;

    for (int r = 0; r < num_rows; r++) {
        int spaces = (max_width - current_width / 2);
    }
   }
}

// row: lignes, col: colonne.

// Aire Rectangle: Aire=Longueur×largeur(𝐴=𝐿×𝑙)


/*    
    for (int row = 0; row < y; row++) {
        for (int col = 0; col < x; col++) {
            if ((row == 0 || row == y - 1) && (col == 0 || col == x - 1)) {
                putchar('*');
            }
            else if (row == 0 || row == y - 1) {
                putchar('*');
            }
            else if (col == 0 || col == x - 1) {
                putchar('|');
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}
*/


int main(int ac, char **av) { 
    if (ac != 3) {
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