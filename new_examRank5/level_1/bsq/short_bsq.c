#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map {
	size_t height, width;
	char empty_c, obst_c, full_c;
	char **grid;
} t_map;

static int check_obstacle(const t_map *m, size_t x0, size_t y0, size_t size)
{
	for (size_t y = y0; y < y0 + size; ++y)
		for (size_t x = x0; x < x0 + size; ++x)
			if (m->grid[y][x] == m->obst_c)
				return 1;
	return 0;
}

static int process_file(const char *path)
{
	FILE *f = path ? fopen(path, "r") : stdin;
	if (!f) {
		fputs("map error\n", stderr);
		return -1;
	}

	t_map m = {0};
	char *line = NULL;
	size_t cap = 0;
	ssize_t len;

	// Parse header
	fscanf(f, " %zu %c %c %c\n", &m.height, &m.empty_c, &m.obst_c, &m.full_c);
	if (m.height == 0 || m.empty_c == m.obst_c || m.empty_c == m.full_c || m.obst_c == m.full_c) {
		fputs("map error\n", stderr);
		fclose(f);
		return -1;
	}

	// Read grid
	m.grid = (char **)calloc(m.height, sizeof(char *));
	if (!m.grid) {
		fputs("map error\n", stderr);
		fclose(f);
		return -1;
	}

	for (size_t r = 0; r < m.height; ++r) {
		len = getline(&line, &cap, f);
		if (len <= 0 || line[len - 1] != '\n') {
			fputs("map error\n", stderr);
			fclose(f);
			return -1;
		}
		line[--len] = '\0';
		if (r == 0) m.width = len;
		else if ((size_t)len != m.width) {
			fputs("map error\n", stderr);
			fclose(f);
			return -1;
		}
		for (size_t c = 0; c < m.width; ++c)
			if (line[c] != m.empty_c && line[c] != m.obst_c) {
				fputs("map error\n", stderr);
				fclose(f);
				return -1;
			}
		m.grid[r] = malloc(m.width + 1);
		if (!m.grid[r]) {
			fputs("map error\n", stderr);
			fclose(f);
			return -1;
		}
		for (size_t c = 0; c <= m.width; ++c)
			m.grid[r][c] = line[c];
	}

	// Solve
	size_t best_size = 0, best_x = 0, best_y = 0;
	for (size_t y = 0; y < m.height; ++y) {
		for (size_t x = 0; x < m.width; ++x) {
			for (size_t sz = 1; y + sz <= m.height && x + sz <= m.width; ++sz) {
				if (check_obstacle(&m, x, y, sz))
					break;
				if (sz > best_size) {
					best_size = sz;
					best_x = x;
					best_y = y;
				}
			}
		}
	}

	// Fill and print
	for (size_t i = 0; i < best_size; ++i)
		for (size_t j = 0; j < best_size; ++j)
			m.grid[best_y + i][best_x + j] = m.full_c;
	for (size_t r = 0; r < m.height; ++r) {
		fputs(m.grid[r], stdout);
		fputc('\n', stdout);
	}

	free(line);
	if (path)
		fclose(f);
	return 0;
}

int main(int ac, char **av)
{
	if (ac <= 1) {
		process_file(NULL);
		fputc('\n', stdout);
		return 0;
	}
	for (int i = 1; i < ac; ++i) {
		process_file(av[i]);
		fputc('\n', stdout);
	}
	return 0;
}