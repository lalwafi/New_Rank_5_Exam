#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	size_t	width;
	size_t	height;
	char	empty_c;
	char	obst_c;
	char	full_c;
	char	**grid;
} t_map;

static int parse_header(FILE *f, t_map *m)
{
	size_t lines = 0;
	char e = 0, o = 0, x = 0;

	int n = fscanf(f, " %zu %c %c %c\n", &lines, &e, &o, &x);
	if (n != 4 || lines == 0 || e == o || e == x || o == x)
		return -1;
	
	m->height = lines;
	m->empty_c = e;
	m->obst_c = o;
	m->full_c = x;
	return 0;
}

static int read_lines(FILE *f, t_map *m)
{
	m->grid = (char **)calloc(m->height, sizeof(char *));
	if (!m->grid)
		return -1;

	char 
}

