#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	int height;
	int width;
	char empty;
	char obst;
	char full;
	char **grid;

	int y;
	int x;
	int size;
}	t_map;

void	freeMap(t_map *m)
{
	if (!m || !m->grid)
		return ;
	for (int i = 0; i < m->height; i++)
		free(m->grid[i]);
	free(m->grid);
	m->grid = NULL;
}



int fillElements(FILE *f, t_map *m)
{
	int i = fscanf(f, "%d%c%c%c", &m->height, &m->empty, &m->obst, &m->full);
	if (i != 4 || m->height <= 0 || m->empty == m->obst || m->empty == m->full || m->obst == m->full)
		return -1;
	
	if (m->empty < 32 || m->empty > 126) return -1;
	if (m->obst < 32 || m->obst > 126) return -1;
	if (m->full < 32 || m->full > 126) return -1;
	
	m->width = 0;
	m->x = 0;
	m->y = 0;
	m->size = 0;
	return 0;
}

int parseMap(FILE *f, t_map *m)
{
	m->grid = (char **)malloc((m->height + 1) * sizeof(char *));
	if (!m->grid)
		return -1;
	m->grid[m->height] = NULL;

	char *line = NULL;
	size_t cap;
	if (getline(&line, &cap, f) == -1)
	{
		freeMap(m);
		return -1;
	}

	for (int i = 0; i < m->height; i++)
	{
		int len = getline(&line, &cap, f);
		if (len == -1 || len - 1 <= 0 || line[len - 1] != '\n')
		{
			free(line);
			freeMap(m);
			return -1;
		}

		line[len - 1] = '\0';
		len--;

		if (i == 0)
			m->width = len;
		else if (len != m->width)
		{
			free(line);
			freeMap(m);
			return -1;
		}

		for (int x = 0; x < len; x++)
		{
			if (!(line[x] == m->empty || line[x] == m->obst))
			{
				free(line);
				freeMap(m);
				return -1;
			}
		}

		m->grid[i] = (char *)malloc((m->width + 1));
		if (!m->grid[i])
		{
			free(line);
			freeMap(m);
			return -1;
		}

		for (int x = 0; x <= m->width; x++)
			m->grid[i][x] = line[x];
	}
	free(line);
	return 0;
}

void	findBiggestSquare(t_map *m)
{
	int matrix[m->height][m->width];
	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			if (m->grid[y][x] == m->obst)
				matrix[y][x] = 0;
			else if (x == 0 || y == 0)
				matrix[y][x] = 1;
			else
			{
				int min = matrix[y - 1][x - 1];
				if (min > matrix[y - 1][x])
					min = matrix[y - 1][x];
				if (min > matrix[y][x - 1])
					min = matrix[y][x - 1];
				matrix[y][x] = min + 1;
			}

			if (matrix[y][x] > m->size)
			{
				m->y = y - matrix[y][x] + 1;
				m->x = x - matrix[y][x] + 1;
				m->size = matrix[y][x];
			}
		}
	}
}

void	fillAndPrint(t_map *m)
{
	for (int y = m->y; y < (m->y + m->size); y++)
	{
		for (int x = m->x; x < (m->x + m->size); x++)
		{
			if (y < m->height && x < m->width)
				m->grid[y][x] = m->full;
		}
	}

	for (int y = 0; y < m->height; y++)
		printf("%s\n", m->grid[y]);
}

int execute(FILE *f)
{
	t_map m;
	if (fillElements(f, &m) == -1)
		return -1;
	if (parseMap(f, &m) == -1)
		return -1;
	findBiggestSquare(&m);
	fillAndPrint(&m);
	freeMap(&m);
	return 0;
}

int convertFile(char *path)
{
	FILE *f = fopen(path, "r");
	if (!f)
		return -1;
	int i = execute(f);
	fclose(f);
	return i;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		if (execute(stdin) == -1)
			printf("map error\n");
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			if (convertFile(av[i]) == -1)
				printf("map error\n");
			if (i < ac - 1)
				printf("\n");
		}
	}
	return 0;
}