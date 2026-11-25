#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

static int my_strlen(char* str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

integer_array* my_count_on_it(string_array* param_1)
{
    if (param_1 == NULL) {
        return NULL;
    }

    integer_array* res = (integer_array*)malloc(sizeof(integer_array));
    if (res == NULL) {
        return NULL;
    }

    res->size = param_1->size;
    res->array = (int*)malloc(sizeof(int) * param_1->size);
    if (res->array == NULL) {
        free(res);
        return NULL;
    }

    for (int i = 0; i < param_1->size; i++) {
        res->array[i] = my_strlen(param_1->array[i]);
    }

    return res;
}