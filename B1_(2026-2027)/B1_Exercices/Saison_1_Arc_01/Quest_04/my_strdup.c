#include <stdlib.h>

static int my_strlen(char* str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* my_strdup(char* param_1)
{
    if (param_1 == NULL) {
        return NULL;
    }

    int len = my_strlen(param_1);
    char* dup = (char*)malloc(sizeof(char) * (len + 1));
    if (dup == NULL) {
        return NULL;
    }

    for (int i = 0; i <= len; i++) {
        dup[i] = param_1[i];
    }

    return dup;
}