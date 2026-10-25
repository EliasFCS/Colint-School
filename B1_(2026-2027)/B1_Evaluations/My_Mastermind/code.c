#include "header.h"

int is_valid_code(const char *code)
{
int i = 0;
int j = 0;

if (!code || my_strlen(code) != CODE_SIZE) {
    return 0;
}

while (i < CODE_SIZE) {
    if (code[i] < '0' || code[i] > '8') {
        return 0;
    }
    j = i + 1;
    while (j < CODE_SIZE) {
        if (code[i] == code[j]) {
            return 0;
        }
        j++;
    }
    i++;
}
return 1;

}

char *generate_random_code(void)
{
static char code[CODE_SIZE + 1];
int count = 0;
int i;
int exists;
char digit;

srand((unsigned int)time(NULL));
while (count < CODE_SIZE) {
    digit = '0' + rand() % 9;
    exists = 0;
    i = 0;
    while (i < count) {
        if (code[i] == digit) {
            exists = 1;
        }
        i++;
    }
    if (!exists) {
        code[count] = digit;
        count++;
    }
}
code[CODE_SIZE] = '\0';
return code;

}