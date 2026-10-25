#ifndef MY_NGRAM_H
# define MY_NGRAM_H

# include <stdio.h>

# define MAX_ASCII 128

void fill_ngram(int *counts, char *str);
void print_ngram(int *counts);

#endif