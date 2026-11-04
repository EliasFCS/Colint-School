typedef struct s_string_array
{
    int size;
    char** array;
} string_array;

string_array* my_split(char* param_1, char* param_2)
{
    if (param_1 == ((void*)0) || param_1[0] == '\0') {
        string_array* res = (string_array*)malloc(sizeof(string_array));
        if (res != ((void*)0)) {
            res->size = 0;
            res->array = ((void*)0);
        }
        return res;
    }

    char sep = (param_2 != ((void*)0) && param_2[0] != '\0') ? param_2[0] : '\0';

    int i = 0;
    int count = 0;
    int in_word = 0;

    while (param_1[i] != '\0') {
        if (param_1[i] != sep) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
        i++;
    }

    string_array* res = (string_array*)malloc(sizeof(string_array));
    if (res == ((void*)0)) {
        return ((void*)0);
    }
    res->size = count;

    if (count == 0) {
        res->array = ((void*)0);
        return res;
    }

    res->array = (char**)malloc(sizeof(char*) * count);
    if (res->array == ((void*)0)) {
        return ((void*)0);
    }

    int current_index = 0;
    i = 0;
    while (param_1[i] != '\0') {
        if (param_1[i] != sep) {
            int start = i;
            while (param_1[i] != '\0' && param_1[i] != sep) {
                i++;
            }
            int len = i - start;
            char* token = (char*)malloc(len + 1);
            if (token != ((void*)0)) {
                int k = 0;
                while (k < len) {
                    token[k] = param_1[start + k];
                    k++;
                }
                token[len] = '\0';
                res->array[current_index++] = token;
            }
        } else {
            i++;
        }
    }

    return res;
}