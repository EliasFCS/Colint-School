#include <unistd.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static void my_putstr(char* str)
{
    if (str == NULL) {
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

void my_print_words_array(string_array* param_1)
{
    if (param_1 == NULL || param_1->array == NULL) {
        return;
    }

    for (int i = 0; i < param_1->size; i++) {
        my_putstr(param_1->array[i]);
        my_putchar('\n');
    }
}