#include "bsq.h"

int load_elements(FILE *fi, t_bsq *bsq)
{
    int n;
    char e, o, f;
    int ret = fscanf(fi," %d%c%c%c\n", &n, &e, &o, &f);
    if (ret != 4)
        return (1);
    if (n <= 0)
        return (1);
    if (e == o || o == f || e == f)
        return (1);
    if (e < 32 || e > 126 || o < 32 || o > 126 || f < 32 || f > 126)
        return (1);
    bsq->e = e;
    bsq->f = f;
    bsq->n = n;
    bsq->o = o;
    return (0);
}

void free_map(char **str)
{
    int i = 0;
    if (str)
    {
        while(str[i])
        {
            free(str[i]);
            i++;
        }
    }
    free (str);
}

int load_map(FILE *f, t_bsq *bs)
{
    bs->h = bs->n;
    bs->grid = (char **) malloc((bs->h + 1) * sizeof(char *));
    bs->grid[bs->h]= NULL;
    char *line = NULL;
    size_t len = 0;

    for(int i = 0 ; i < bs->h; i++)
    {
        int read = getline(&line, &len, f);
        if (read == -1 || line[read - 1] != '\n')
        {
            free(line);
            free_map(bs->grid);
            return (1);
        }
        read--;
        line[read] = '\0';
        if (i == 0)
            bs->w = read;
        else
        {
            if (bs->w != read)
            {
                free(line);
                free_map(bs->grid);
                return (1);
            }
        }
        bs->grid[i] = malloc((bs->w + 1) * sizeof(char));
        for (int j = 0; j < bs->w ; j++)
        {
            char c = line[j];
            if (c != bs->e  && c != bs->o)
            {
                free(line);
                free_map(bs->grid);
                return (1);
            }
            bs->grid[i][j] = c;
        }
        bs->grid[i][bs->w] = '\0';
           
    }
    free (line);
    return (0);
}

int find_min(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return (min);
}

void find_bg_sq(t_bsq *bsq)
{
    int matrix[bsq->h][bsq->w];
    for (int i = 0; i < bsq->h; i++)
    {
        for (int j = 0; j < bsq->w; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < bsq->h; i++)
    {
        for (int j = 0; j < bsq->w; j++)
        {
           if (i == 0 || j == 0)
            matrix[i][j] = 1;
           else if (bsq->grid[i][j] == bsq->o)
            matrix[i][j] = 0;
           else
                matrix[i][j] = find_min(matrix[i][j - 1], matrix[i - 1][j - 1], matrix[i - 1][j]) + 1;
           if (matrix[i][j] > bsq->sq_size)
           {
                bsq->sq_size = matrix[i][j];
                bsq->i = i - bsq->sq_size + 1;
                bsq->j = j - bsq->sq_size + 1;
           }
        }
    }

}

void print_bsq(t_bsq *bsq)
{
    for (int i = bsq->i; i < bsq->sq_size + bsq->i; i++)
    {
        for (int j = bsq->j; j < bsq->sq_size + bsq -> j; j++)
        {
            bsq->grid[i][j] = bsq->f;
        }
    } 

    for (int i = 0; i < bsq->h; i++)
    {
        fputs(bsq->grid[i], stdout);
        fprintf(stdout, "\n");
    }
}
int execute_bsq(FILE *f)
{
    t_bsq  bs;
    if (load_elements(f, &bs))
        return (1);
    if (load_map(f, &bs))
        return (1);
    bs.sq_size = 0;
    bs.i = 0;
    bs.j = 0;
    find_bg_sq(&bs);
    print_bsq(&bs);
    free_map(bs.grid);
    return (0);

}

int file_intrep(char *str)
{
    FILE *f = fopen(str, "r");
    if (execute_bsq(f))
        return (1);
    fclose(f);
    return (0);
}