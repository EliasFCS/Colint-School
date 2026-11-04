#include <stdio.h>
#include <stdlib.h>

char* my_spaceship(char* param_1)
{
    int x = 0;
    int y = 0;
    int dir = 0; 

    const char* directions[] = {"up", "right", "down", "left"};

    if (param_1 != NULL) {
        for (int i = 0; param_1[i] != '\0'; i++) {
            if (param_1[i] == 'R') {
                dir = (dir + 1) % 4;
            } else if (param_1[i] == 'L') {
                dir = (dir + 3) % 4;
            } else if (param_1[i] == 'A') {
                if (dir == 0) {
                    y -= 1;
                } else if (dir == 1) {
                    x += 1;
                } else if (dir == 2) {
                    y += 1;
                } else if (dir == 3) {
                    x -= 1;
                }
            }
        }
    }

    char* result = (char*)malloc(sizeof(char) * 100);
    if (result == NULL) {
        return NULL;
    }

    snprintf(result, 100, "{x: %d, y: %d, direction: '%s'}", x, y, directions[dir]);
    return result;
}