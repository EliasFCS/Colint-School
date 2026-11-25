#include <stddef.h>

char* my_strrchr(char* param_1, char param_2)
{
    if (param_1 == NULL)
        return NULL;

    char* last_occurrence = NULL;

    while (*param_1 != '\0')
    {
        if (*param_1 == param_2)
            last_occurrence = param_1;
        param_1++;
    }

    if (param_2 == '\0')
        return param_1;

    return last_occurrence;
}