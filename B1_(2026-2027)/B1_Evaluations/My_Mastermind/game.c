#include "header.h"

int read_guess(char *buffer)
{
char c;
int len = 0;
int overflow = 0;
ssize_t bytes_read;

while ((bytes_read = read(0, &c, 1)) > 0) {
    if (c == '\n') {
        break;
    }
    if (len < CODE_SIZE) {
        buffer[len] = c;
    } else {
        overflow = 1;
    }
    len++;
}
if (bytes_read == 0 && len == 0) {
    return 0;
}
if (bytes_read < 0) {
    return 0;
}
if (len != CODE_SIZE || overflow) {
    buffer[0] = '\0';
    return 1;
}
buffer[CODE_SIZE] = '\0';
return 1;

}

void evaluate_guess(const char *secret, const char *guess,
int *well_placed, int *misplaced)
{
int used_secret[CODE_SIZE] = {0};
int used_guess[CODE_SIZE] = {0};
int i = 0;
int j;

*well_placed = 0;
*misplaced = 0;

while (i < CODE_SIZE) {
    if (guess[i] == secret[i]) {
        (*well_placed)++;
        used_secret[i] = 1;
        used_guess[i] = 1;
    }
    i++;
}

i = 0;
while (i < CODE_SIZE) {
    if (!used_guess[i]) {
        j = 0;
        while (j < CODE_SIZE) {
            if (!used_secret[j] && guess[i] == secret[j]) {
                (*misplaced)++;
                used_secret[j] = 1;
                break;
            }
            j++;
        }
    }
    i++;
}

}