char* inter(char* param_1, char* param_2)
{
    if (param_1 == ((void*)0)) param_1 = "";
    if (param_2 == ((void*)0)) param_2 = "";

    int len1 = 0;
    while (param_1[len1] != '\0') {
        len1++;
    }

    char* result = (char*)malloc(len1 + 1);
    if (result == ((void*)0)) {
        return ((void*)0);
    }

    int in_p2[256] = {0};
    int i = 0;
    while (param_2[i] != '\0') {
        in_p2[(unsigned char)param_2[i]] = 1;
        i++;
    }

    int added[256] = {0};
    int res_index = 0;

    for (i = 0; i < len1; i++) {
        unsigned char c = (unsigned char)param_1[i];
       
        if (in_p2[c] && !added[c]) {
            added[c] = 1;
            result[res_index++] = param_1[i];
        }
    }

    result[res_index] = '\0';

    return result;
}