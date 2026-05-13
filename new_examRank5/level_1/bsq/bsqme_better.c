#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	size_t	height;
	size_t	width;
	char	empty_c;
	char	obst_c;
	char	full_c;
	char	**grid;
} t_map;

static void	free_map(t_map *m)
{
	if (!m || !m->grid)
		return ;
	for (size_t i = 0; i < m->height; i++)
		free(m->grid[i]);
	free(m->grid);
	m->grid = NULL;
}

static int 	parse_header(FILE *f, t_map *m)
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

static int read_lines(FILE *f, t_map *m)
{
	m->grid = (char **)calloc(m->height, sizeof(char **));
	if (!m->grid)
		return -1;
	
	char *line = NULL;
	size_t cap;
	ssize_t len;

	for (size_t r = 0; r < m->height; r++)
	{
		len = getline(&line, &cap, f);
		if (len < 0 || len == 0 || line[len - 1] != '\n')
		{
			free(line);
			return -1;
		}
		
		line[len - 1] = '\0';
		len -= 1;
		if (len <= 0)
		{
			free(line);
			return -1;
		}
		
		if (r == 0)
			m->width = (size_t) len;
		else if ((size_t)len != m->width)
		{
			free(line);
			return -1;
		}
		
		for (size_t i = 0; i < m->width; i++)
		{
			char c = line[i];
			if (!(c == m->empty_c || c == m->obst_c))
			{
				free(line);
				return -1;
			}
		}

		m->grid[r] = (char *)malloc(m->width + 1);
		if (!m->grid[r])
		{
			free(line);
			return -1;
		}
		
		for (size_t i = 0; i <= m->width; i++)
			m->grid[r][i] = line[i];
	}
	free(line);
	return 0;
}

static int parse_map(FILE *f, t_map *m)
{
	m->height = 0;
	m->width = 0;
	m->obst_c = 0;
	m->full_c = 0;
	m->empty_c = 0;
	m->grid = NULL;

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
				return 1;
		}
	}
	return 0;
}

static void fill_and_print(t_map *m, size_t best_x, size_t best_y, size_t best_size)
{
	if (best_size > 0)
	{
		for (size_t y = 0; y < best_size; y++)
		{
			for (size_t x = 0; x < best_size; x++)
				m->grid[best_y + y][best_x + x] = m->full_c;
		}
	}
	for (size_t y = 0; y < m->height; y++)
	{
		fputs(m->grid[y], stdout);
		fputc('\n', stdout);
	}

	free_map(m);
}

static void	execute(t_map *m)
{
	size_t best_size = 0;
	size_t best_y = 0;
	size_t best_x = 0;

	for (size_t y = 0; y < m->height; y++)
	{
		for (size_t x = 0; x < m->width; x++)
		{
			size_t size_try = 1;
			while ((y + size_try) <= m->height && (x + size_try) <= m->width)
			{
				if (check_obstacles(m, x, y, size_try))
					break;
				if (size_try > best_size)
				{
					best_size = size_try;
					best_y = y;
					best_x = x;
				}
				size_try += 1;
			}
		}
	}

	fill_and_print(m, best_x, best_y, best_size);
}

static int process_stream(FILE *f)
{
	t_map m;
	if (parse_map(f, &m) != 0)
	{
		fputs("map error\n", stderr);
		free_map(&m);
		return -1;
	}
	execute(&m);
	return 0;
}

static int process_file(const char *path)
{
	FILE *f = fopen(path, "r");
	if (!f)
	{
		fputs("map error\n", stderr);
		return -1;
	}
	int rc = process_stream(f);
	fclose(f);
	return rc;
}

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		(void)process_stream(stdin);
		fputc('\n', stdout);
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		(void)process_file(av[i]);
		fputc('\n', stdout);
	}
	return 0;
}


// test_maps/all_obstacles.txt test_maps/full_empty.txt test_maps/single_row.txt test_maps/bad_chars.txt test_maps/minimal.txt test_maps/special_chars.txt test_maps/bad_count.txt test_maps/no_final_newline.txt test_maps/tiebreak.txt test_maps/bad_len.txt test_maps/numeric_chars.txt test_maps/valid_example.txt test_maps/dup_chars.txt test_maps/priority.txt test_maps/zero_rows.txt test_maps/file1.txt test_maps/simple_test.txt test_maps/file2.txt test_maps/single_col.txt