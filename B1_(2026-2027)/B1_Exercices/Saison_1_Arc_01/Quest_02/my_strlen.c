int my_strlen(char* param_1)
{
    int index = 0;

    while (param_1[index] != '\0') {
        index++;
    }

    return index;
}