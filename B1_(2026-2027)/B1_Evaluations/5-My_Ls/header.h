#ifndef HEADER_H
#define HEADER_H

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

typedef struct s_file
{
    char *name;
    time_t sec;
    long nsec;
} t_file;

typedef struct s_operand
{
    char *name;
    int is_dir;
    time_t sec;
    long nsec;
} t_operand;

void my_ls(int argc, char *argv[]);

#endif