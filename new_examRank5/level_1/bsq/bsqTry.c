#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	int height;
	int width;
	char e;
	char o;
	char f;
	char **grid;

	int x;
	int y;
	int size;
} t_map;


int getElements(FILE *f, t_map *m)
{
	int i = fscanf(f, "%d%c%c%c", &m->height, &m->e, &m->o, &m->f);
	if (i != 4 || m->height <= 0 || m->e == m->o || m->e == m->f || m->o == m->f)
		return -1;
	
	if (m->e < 32 || m->e > 126)	return -1;
	if (m->o < 32 || m->o > 126)	return -1;
	if (m->f < 32 || m->f > 126)	return -1;

	m->width = 0;
	m->grid = NULL;
	m->x = 0;
	m->y = 0;
	m->size = 0;
	return 0;
}

int parseMap(FILE *f, t_map *m)
{
	char *line = NULL;
	size_t cap = 0;
	if (getline(&line, &cap, f) == -1)	return -1;

	m->grid = (char **)malloc((m->height + 1) * sizeof(char *));
	if (!m->grid)
	{
		free(line);
		return -1;
	}

	for (int i = 0; i < m->height; i++)
	{
		
	}
}

int execute(FILE *f)
{
	t_map m;
	if (getElements(f, &m) == -1)	return -1;
	if (parseMap(f, &m) == -1)		return -1;
	findBigSquare(&m);
	fillAndPrint(&m);
	freeMap(&m);
	return 0;
}

int getFile(char *path)
{
	FILE *f = fopen(path, "r");
	if (!f) return -1;
	int i = execute(f);
	fclose(f);
	return 0;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		if (getFile(stdin) == -1)
			fprintf(stdout, "map error\n");
	}
	else
	{
		for(int i = 1; i < ac; i++)
		{
			if (execute(av[i]) == -1)
				fprintf(stdout, "map error\n");
			if (i < ac - 1)
				fprintf(stdout, "\n");
		}
	}
	return 0;
}