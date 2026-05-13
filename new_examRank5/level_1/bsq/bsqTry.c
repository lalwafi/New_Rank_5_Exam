#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_map
{
	int height;
	int width;
	char empty_c;
	char obst_c;
	char full_c;
	char **grid;
} t_map;

static void free_map(t_map *m)
{
	if (!m || !m->grid)
		return ;
	for (size_t i = 0; i < m->height; i++)
		free(m->grid[i]);
	free(m->grid);
	m->grid = NULL;
}

static int parse_header(FILE *f, t_map *m)
{
	size_t y = 0;
	char e = 0, o = 0, full = 0;
	int n = fscanf(f, " %zu %c %c %c\n", &y, &e, &o, &full);
	if (n != 4 || y == 0 || e == o || e == full || o == full)
		return -1;
	m->height = y;
	m->empty_c = e;
	m->obst_c = o;
	m->full_c = full;
	return 0;
}

int read_lines(FILE *f, t_map *m)
{
	m->grid = (char **)calloc(m->height, sizeof(char *));
	if (!m->grid)
		return -1;
	size_t cap;
	ssize_t len;
	char *line;
	for (size_t i = 0; i < m->height; i++)
	{
		len = getline(&line, &cap, f);
		if (len < 0 || len == 0 || line[len - 1] != '\n')
		{
			free(line);
			return -1;
		}

		line[len - 1] = '\0'
		len -= 1;
		if (len <= 0)
		{
			free(line);
			return -1;
		}

		if (i == 0)
			m->width = (size_t)len;
		else if ((size_t)len != m->width)
		{
			free(line);
			return -1;
		}

		for (size_t x = 0; x < m->width; x++)
		{
			char c = line[i];
			if (!(c == m->empty_c || c == m->obst_c))
			{
				free(line);
				return -1;
			}
		}
		m->grid[i] = (char *)malloc(m->width + 1);
		if (!m->grid[i])
		{
			free(line);
			return -1;
		}
		
		for (size_t x = 0; x < m->width; x++)
			m->grid[i][x] = line[x];
	}
	free(line)
	return 0;
}

static int parse_map(FILE *f, t_map *m)
{
	m->grid = NULL;
	m->height = 0;
	m->width = 0;
	m->empty_c = 0;
	m->obst_c = 0;
	m->full_c = 0;
	
	if (parse_header(f, m) != 0)
		return -1;
	if (read_lines(f, m) != 0)
	{
		free_map(m);
		return -1;
	}
	return 0;
}

static int check_obstacles(const t_map *m, size_t x0, size_t y0, size_t size_try)
{
	size_t x_end = x0 + size_try;
	size_t y_end = y0 + size_try;
	for (size_t y = y0; y < y_end; y++)
	{
		for (size_t x = x0; x < x_end; x++)
		{
			if (m->grid[y][x] == m->obst_c)
				return -1;
		}
	}
	return 0;
}

static void fill_and_print(t_map *m, size_t x_best, size_t y_best, size_t size_best)
{
	if (size_best > 0)
	{
		for (size_t y = 0; y < size_best; y++)
		{
			for (size_t x = 0; x < size_best; x++)
				m->grid[y][x] = m->full_c;
		}
	}
	for (size_t y = 0; y < m->height; y++)
	{
		fputs(m->grid[y], stdout);
		fputc('\n', stdout);
	}
	free_map(m);
}

static void execute(t_map *m)
{
	
}

int main(int ac, char **av)
{
	if (ac <= 1)
	{

	}
}
