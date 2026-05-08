#include "life.h"

void fill_grid (t_life *life)
{
    char  buff;
    while(read(0, &buff, 1) > 0)
    {
        switch(buff)
        {
            case  'w':
            {
                if (life->i > 0)
                    life->i--;
                break;
            }
            case  'a':
            {
                if (life->j > 0)
                    life->j--;
                break;
            }
            case  's':
            {
                if (life->i < (life->h - 1))
                    life->i++;
                break;
            }
            case  'd':
            {
                if (life->j < (life->w - 1))
                    life->j++;
                break;
            }
            case  'x':
            {
                life->draw = !(life->draw);
                break;
            }
        }
        if (life->draw)
        {
           life->grid[life->i][life->j] = life->alive;
        }

    }
}

int count_neighbor(t_life *life, int i, int j)
{
    int ni = 0;
    int nj = 0;
    int c = 0;
    for (int di = -1; di < 2; di++)
    {
        for (int dj = -1; dj < 2; dj++)
        {
            if (di == 0 && dj == 0)
                continue;
            ni = i + di;
            nj = i + dj;
            if (ni > 0 && nj > 0 && ni < life->h && nj < life->w)
                c++;
        }
    }
    return (c);
}

void free_map(char **str)
{   int i = 0;
    if (str)
    {
        while (str[i])
        {
            free(str[i]);
            i++;
        }


    }
    free (str);
}

int play(t_life *life)
{
    char **temp = (char **) malloc ((life->h + 1) * sizeof(char *));
    for (int k = 0; k < life->h; k++)
    {
        life->grid[k] = malloc ((life->w + 1) * sizeof(char));
        for (int o = 0; o <life->w; o++)
        {
            life->grid[k][o] = ' ';
        }
        life->grid[k][life->w] = '\0';
    }

    for (int i = 0; i < life->h; i++)
    {
        for (int j = 0; j < life->w; j++)
        {
            int c = count_neighbor(life, i, j);
            if (life->grid[i][j] == life->alive)
            {
                if (c < 2 && c > 3)
                    temp[i][j] = life->dead;
                else
                    temp[i][j] = life->alive;
            }
            else{
                if (c == 3)
                    temp[i][j] = life->alive;
                else
                    temp[i][j] = life->dead;
            }
        }
    }

    free_map(life->grid);
    life->grid = temp;
    return (1);
}

void print_grid(t_life *life)
{
     for (int k = 0; k < life->h; k++)
    {
        for (int o = 0; o <life->w; o++)
        {
            putchar(life->grid[k][o]);
        }
        putchar('\n');
    }
}


int main(int av, char **ac)
{
    if (av != 4)
        return (1);
    t_life life;
    life.alive = 'O';
    life.dead = ' ';
    life.w = atoi(ac[1]);
    life.h = atoi(ac[2]);
    life.iter = atoi(ac[3]);
    life.i = 0;
    life.j = 0;
    life.grid = (char **) malloc ((life.h + 1) * sizeof(char *));
    for (int k = 0; k < life.h; k++)
    {
        life.grid[k] = malloc ((life.w + 1) * sizeof(char));
        for (int o = 0; o <life.w; o++)
        {
            life.grid[k][o] = ' ';
        }
        life.grid[k][life.w] = '\0';
    }
    life.grid[life.h] = NULL;

    fill_grid(&life);

    for (int i = 0; i < life.iter; i++)
    {
        if (!play(&life))
            return (1);
    }
    print_grid(&life);
    return (0);
}