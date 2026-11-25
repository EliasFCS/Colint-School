int hidenp(char* param_1, char* param_2)
{
    if (param_1 == ((void*)0) || param_2 == ((void*)0)) {
        return 0;
    }

    int i = 0; 
    int j = 0; 

    // Traverse both strings
    while (param_1[i] != '\0' && param_2[j] != '\0') {
        if (param_1[i] == param_2[j]) {
            i++; 
        }
        j++; 
    }

    return (param_1[i] == '\0') ? 1 : 0;
}