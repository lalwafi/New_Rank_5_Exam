#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	int width;
	int height;
	char empty_c;
	char obst_c;
	char full_c;
	char **grid;

	int y;
	int x;
	int size;
}	t_map;

void	freeMap(char **arr);
void	fillAndPrint(t_map *m);
void findBiggestSquare(t_map *m);
int getElements(FILE *f, t_map *m);
int parseMap(FILE *f, t_map *m);
int	convertFile(char *name);
int	execute(FILE *f);




int main(int ac, char **av)
{
	if (ac == 1)
	{
		if (execute(stdin) == -1)
			fprintf(stdout, "map error\n");
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			if (convertFile(av[i]) == -1)
				fprintf(stdout, "map error\n");
			if (i < ac - 1)
				fprintf(stdout, "\n");
		}
	}
	return 0;
}

int	convertFile(char *name)
{
	FILE *f = fopen(name, "r");
	if (!f)
		return -1;
	int i = 0;
	i = execute(f);
	fclose(f);
	return i;
}

int	execute(FILE *f)
{
	t_map m;
	if (getElements(f, &m) == -1)
		return -1;
	if (parseMap(f, &m) == -1)
		return -1;
	findBiggestSquare(&m);
	fillAndPrint(&m);
	freeMap(m.grid);
	return 0;
}

int getElements(FILE *f, t_map *m)
{
	int i = fscanf(f, "%d%c%c%c", &m->height, &m->empty_c, &m->obst_c, &m->full_c);
	if (i != 4 || m->height <= 0 || m->empty_c == m->obst_c || m->empty_c == m->full_c || m->obst_c == m->full_c)
		return -1;
	
	// check valid chars
	if (m->empty_c < 32 || m->empty_c > 126) return -1;
	if (m->obst_c < 32 || m->obst_c > 126) return -1;
	if (m->full_c < 32 || m->full_c > 126) return -1;

	m->width = 0;
	m->y = 0;
	m->x = 0;
	m->size = 0;
	
	return 0;
}

int parseMap(FILE *f, t_map *m)
{
	// check if theres anything and skip first line
	char *line = NULL;
	size_t cap;
	if (getline(&line, &cap, f) == -1) return -1;
	
	// allocate grid
	m->grid = (char **)malloc((m->height + 1) * sizeof(char *));
	if (!m->grid)
	{
		free(line);
		return -1;
	}
	m->grid[m->height] = NULL;

	// get each line
	for (int i = 0; i < m->height; i++)
	{
		// get line and make sure its not empty and ends in \n
		int len = getline(&line, &cap, f);
		if (len == -1 || (len - 1) <= 0 || line[len - 1] != '\n')
		{
			free(line);
			freeMap(m->grid);
			return -1;
		}

		// change the \n to \0
		line[len - 1] = '\0';
		len--;

		// set width if not set, then check that each line is the same length
		if (i == 0)
			m->width = len;
		else if (m->width != len)
		{
			free(line);
			freeMap(m->grid);
			return -1;
		}

		// check map for invalid characters
		for (int j = 0; j < m->width; j++)
		{
			if (!(line[j] == m->empty_c || line[j] == m->obst_c))
			{
				free(line);
				freeMap(m->grid);
				return -1;
			}
		}

		// allocate grid line and add it
		m->grid[i] = (char *)malloc(m->width + 1);
		if (!m->grid[i])
		{
			free(line);
			freeMap(m->grid);
			return -1;
		}

		for (int x = 0; x <= m->width; x++)
			m->grid[i][x] = line[x];
	}
	free(line);
	return 0;
}

void findBiggestSquare(t_map *m)
{
	int matrix[m->height][m->width];

	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			if (m->grid[y][x] == m->obst_c)
				matrix[y][x] = 0;
			else if (y == 0 || x == 0)
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
				m->size = matrix[y][x];
				m->y = y - matrix[y][x] + 1;
				m->x = x - matrix[y][x] + 1;
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
			if ((y < m->height) && (x < m->width))
				m->grid[y][x] = m->full_c;
		}
	}

	for (int y = 0; y < m->height; y++)
		fprintf(stdout, "%s\n", m->grid[y]);
}

void	freeMap(char **arr)
{
	if (arr)
	{
		for (int i = 0; arr[i] != NULL; i++)
		{
			if (arr[i] != NULL)
				free(arr[i]);
		}
		free(arr);
	}
}