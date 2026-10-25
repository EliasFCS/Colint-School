#include <stdlib.h>
#include <stdio.h>


char* hello_name(char* param_1)
{
    int len = 0;
    while (param_1[len] != '\0') {
        len++;
    }

    char* result = (char*)malloc(sizeof(char) * (6 + len + 1));
    if (result == NULL) {
        return NULL;
    }

    char prefix[] = "Hello ";
    int i = 0;
    for (; i < 6; i++) {
        result[i] = prefix[i];
    }

    int j = 0;
    while (param_1[j] != '\0') {
        result[i + j] = param_1[j];
        j++;
    }

    result[i + j] = '\0';

    return result;
}