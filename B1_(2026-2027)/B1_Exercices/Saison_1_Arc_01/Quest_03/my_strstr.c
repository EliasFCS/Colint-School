#include <stddef.h>

char* my_strstr(char* param_1, char* param_2)
{
    if (param_1 == NULL || param_2 == NULL)
        return NULL;

    if (*param_2 == '\0')
        return param_1;

    for (int i = 0; param_1[i] != '\0'; i++)
    {
        int j = 0;
        while (param_2[j] != '\0' && param_1[i + j] != '\0' && param_1[i + j] == param_2[j])
        {
            j++;
        }

        if (param_2[j] == '\0')
            return &param_1[i];
    }

    return NULL;
}