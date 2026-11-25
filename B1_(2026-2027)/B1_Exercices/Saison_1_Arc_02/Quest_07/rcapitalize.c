char* rcapitalize(char* param_1)
{
    if (param_1 == ((void*)0)) {
        return ((void*)0);
    }

    int i = 0;
    while (param_1[i] != '\0') {

        while (param_1[i] == ' ' || param_1[i] == '\t') {
            i++;
        }
        
        if (param_1[i] == '\0') {
            break;
        }

        int j = i;
        while (param_1[j] != '\0' && param_1[j] != ' ' && param_1[j] != '\t') {
            j++;
        }

        int last_char_idx = j - 1;

        for (int k = i; k < j; k++) {
            char c = param_1[k];
            if (k == last_char_idx) {
               
                if (c >= 'a' && c <= 'z') {
                    param_1[k] = c - 32;
                }
            } else {
               
                if (c >= 'A' && c <= 'Z') {
                    param_1[k] = c + 32;
                }
            }
        }

        i = j;
    }

    return param_1;
}