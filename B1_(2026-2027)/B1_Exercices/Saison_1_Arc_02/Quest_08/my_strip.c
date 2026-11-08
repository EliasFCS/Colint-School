char* my_strip(char* param_1)
{
    if (param_1 == ((void*)0)) {
        char* empty = (char*)malloc(1);
        if (empty != ((void*)0)) {
            empty[0] = '\0';
        }
        return empty;
    }

    int len = 0;
    while (param_1[len] != '\0') {
        len++;
    }

    char* result = (char*)malloc(len + 1);
    if (result == ((void*)0)) {
        return ((void*)0);
    }

    int i = 0;
    while (param_1[i] == ' ' || param_1[i] == '\t') {
        i++;
    }

    int res_idx = 0;

    while (param_1[i] != '\0') {
        if (param_1[i] == ' ' || param_1[i] == '\t') {
            
            int temp = i;
            int has_more_chars = 0;
            while (param_1[temp] != '\0') {
                if (param_1[temp] != ' ' && param_1[temp] != '\t') {
                    has_more_chars = 1;
                    break;
                }
                temp++;
            }

            if (has_more_chars) {
                if (res_idx > 0 && result[res_idx - 1] != ' ') {
                    result[res_idx++] = ' ';
                }
            }

            while (param_1[i] == ' ' || param_1[i] == '\t') {
                i++;
            }
        } else {
            result[res_idx++] = param_1[i];
            i++;
        }
    }

    result[res_idx] = '\0';

    return result;
}