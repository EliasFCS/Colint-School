#include <stddef.h>

char* reverse_string(char* param_1)
{
    if (param_1 == NULL)
        return NULL;

    int len = 0;
    while (param_1[len] != '\0')
    {
        len++;
    }

    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        char temp = param_1[start];
        param_1[start] = param_1[end];
        param_1[end] = temp;
        start++;
        end--;
    }

    return param_1;
}