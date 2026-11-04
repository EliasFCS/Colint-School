int is_anagram(char* param_1, char* param_2)
{
    if (param_1 == ((void*)0) || param_2 == ((void*)0)) {
        return (param_1 == param_2) ? 1 : 0;
    }

    int count[256] = {0};
    int len1 = 0;
    int len2 = 0;

    while (param_1[len1] != '\0') {
        count[(unsigned char)param_1[len1]]++;
        len1++;
    }

    while (param_2[len2] != '\0') {
        len2++;
    }

    if (len1 != len2) {
        return 0;
    }

    // 3. Decrement counts using param_2
    for (int i = 0; i < len2; i++) {
        unsigned char c = (unsigned char)param_2[i];
        count[c]--;
        
        if (count[c] < 0) {
            return 0;
        }
    }

    return 1;
}