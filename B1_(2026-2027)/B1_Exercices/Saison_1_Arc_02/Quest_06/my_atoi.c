int my_atoi(char* param_1)
{
    if (param_1 == ((void*)0)) {
        return 0;
    }

    int i = 0;
    int sign = 1;
    long long result = 0;

    while (param_1[i] == ' ' || (param_1[i] >= '\t' && param_1[i] <= '\r')) {
        i++;
    }

    if (param_1[i] == '-') {
        sign = -1;
        i++;
    } else if (param_1[i] == '+') {
        i++;
    }

    while (param_1[i] >= '0' && param_1[i] <= '9') {
        result = result * 10 + (param_1[i] - '0');
        i++;
    }

    return (int)(result * sign);
}