#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_life
{
    char  alive;
    char  dead;
    int   w;
    int   h;
    int   iter;
    int    i;
    int    j;
    char**  grid;
    int   draw;
} t_life;




#endif