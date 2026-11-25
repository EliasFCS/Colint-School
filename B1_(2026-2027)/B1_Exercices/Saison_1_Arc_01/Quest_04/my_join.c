#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

static int my_strlen(char* str)
{
    if (str == NULL) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* my_join(string_array* param_1, char* param_2)
{
    if (param_1 == NULL || param_1->size == 0 || param_1->array == NULL) {
        return NULL;
    }

    int sep_len = my_strlen(param_2);
    int total_len = 0;

    for (int i = 0; i < param_1->size; i++) {
        total_len += my_strlen(param_1->array[i]);
    }

    if (param_1->size > 1) {
        total_len += (param_1->size - 1) * sep_len;
    }

    char* result = (char*)malloc(sizeof(char) * (total_len + 1));
    if (result == NULL) {
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < param_1->size; i++) {
        char* current_word = param_1->array[i];
        if (current_word != NULL) {
            for (int j = 0; current_word[j] != '\0'; j++) {
                result[idx++] = current_word[j];
            }
        }

        if (i < param_1->size - 1 && param_2 != NULL) {
            for (int j = 0; param_2[j] != '\0'; j++) {
                result[idx++] = param_2[j];
            }
        }
    }

    result[idx] = '\0';
    return result;
}