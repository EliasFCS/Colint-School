#include <unistd.h>


void my_putstr(char* param_1)
{
    if (param_1 == NULL) {
        return;
    }
    
    int index = 0;
    while (param_1[index] != '\0') {
        write(1, &param_1[index], 1);
        index++;
    }
}