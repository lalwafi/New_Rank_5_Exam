#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_bsq{
    int  n;
    int e;
    int o;
    int f;
    char **grid;
    int  h;
    int  w;
    int  sq_size;
    int  i;
    int  j;
} t_bsq;

int execute_bsq(FILE *stdin);
int file_intrep(char *str);

#endif