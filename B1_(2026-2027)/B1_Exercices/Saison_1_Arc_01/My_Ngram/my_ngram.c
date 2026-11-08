#include "my_ngram.h"

void fill_ngram(int *counts, char *str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '"') {
            unsigned char c = (unsigned char)str[i];
            if (c < MAX_ASCII) {
                counts[c]++;
            }
        }
        i++;
    }
}

void print_ngram(int *counts) {
    for (int i = 0; i < MAX_ASCII; i++) {
        if (counts[i] > 0) {
            printf("%c:%d\n", i, counts[i]);
        }
    }
}

int main(int ac, char **av) {
    int counts[MAX_ASCII] = {0};

    for (int i = 1; i < ac; i++) {
        fill_ngram(counts, av[i]);
    }

    print_ngram(counts);

    return 0;
}