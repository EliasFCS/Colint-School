#include <stdio.h>
#include <stdlib.h>

void my_square(int x, int y) {
    if (x <= 0 || y <= 0) {
        return;
    }

    for (int row = 0; row < y; row++) {
        for (int col = 0; col < x; col++) {
            if ((row == 0 || row == y - 1) && (col == 0 || col == x - 1)) {
                putchar('o');
            }
            else if (row == 0 || row == y - 1) {
                putchar('-');
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

int main(int ac, char **av) {
    if (ac != 3) {
        return 0;
    }

    int x = atoi(av[1]);
    int y = atoi(av[2]);

    my_square(x, y);

    return 0;
}