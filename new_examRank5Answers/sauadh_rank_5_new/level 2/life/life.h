#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_life
{
    int   w;
    int   h;
    int   iter;
    char  alive;
    char  dead;
    int   draw;
    char**  grid;
    int    i;
    int    j;
} t_life;




#endif