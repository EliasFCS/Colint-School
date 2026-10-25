#include <stdio.h>
#include <stdlib.h>


// Définission fonction

void my_christmas_tree(int x, int y) {
    if (x <= 0 || y <= 0) {
        return; 
    }

    
}











// Utiliser la fonction en ./a.out appel de fonction

int main(int ac, char **av) {
    if (ac != 3) {
        return 0;
    }
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    my_christmas_tree(x, y);
    return 0;
}