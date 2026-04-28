#include "bsq.h"

int	read_chars(FILE *file, t_map *map)
{
	if (fscanf(file, "%d%c%c%c\n", &map->hei, &map->chars.empty, &map->chars.obstacle, &map->chars.full) != 4)
		return (1);
	if (map->hei <= 0)
		return (1);
	if (map->chars.empty == map->chars.full || map->chars.empty == map->chars.obstacle || map->chars.full == map->chars.obstacle)
		return (1);
	if (map->chars.empty < 32 || map->chars.empty > 126)
		return (1);
	if (map->chars.full < 32 || map->chars.full > 126)
		return (1);
	if (map->chars.obstacle < 32 || map->chars.obstacle > 126)
		return (1);
	return (0);
}

void	free_grid(t_map *map)
{
	if (map->grid)
	{
		for (int i = 0; i < map->hei; i++)
		{
			if (map->grid[i])
				free(map->grid[i]);
		}
		free(map->grid);
	}
}

int	read_map(FILE *file, t_map *map)
{
	char	*line = NULL;
	ssize_t	bytes;
	size_t	len = 0;

	if (read_chars(file, map))
		return (1);
	map->grid = malloc((map->hei+1) * sizeof(char*));
	if (!map->grid)
		return (1);
	map->grid[map->hei] = NULL;
	for (int i = 0; i < map->hei; i++)
	{
		bytes = getline(&line, &len, file);
		if (bytes <= 1)
			return (free_grid(map), free(line), 1);
		if (line[bytes - 1] != '\n')
			return (free_grid(map), free(line), 1);
		if (!i)
			map->wid = bytes - 1;
		else
		{
			if (bytes - 1 != map->wid)
				return (free(line), free_grid(map), 1);
		}
		map->grid[i] = malloc((map->wid+1) * sizeof(char));
		if (!map->grid[i])
			return (free_grid(map), free(line), 1);
		map->grid[i][map->wid] = 0;
		for (int j = 0; j < map->wid; j++)
		{
			if (line[j] != map->chars.empty && line[j] != map->chars.obstacle)
				return (free_grid(map), free(line), 1);
			map->grid[i][j] = line[j];
		}
	}
	free(line);
	return (0);
}

int	min(int n1, int n2, int n3)
{
	int	min;
	min = n1;
	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return (min);
}

void	find_bsq(t_map *map, t_sq *bsq)
{
	int	arr[map->hei][map->wid];

	bsq->size = 0;
	bsq->x = 0;
	bsq->y = 0;
	for (int i = 0; i < map->hei; i++)
	{
		for (int j = 0; j < map->wid; j++)
			arr[i][j] = 0;
	}
	for (int i = 0; i < map->hei; i++)
	{
		for (int j = 0; j < map->wid; j++)
		{
			if (map->grid[i][j] == map->chars.obstacle)
				arr[i][j] = 0;
			else if (i == 0 || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = min(arr[i-1][j], arr[i-1][j-1], arr[i][j-1]) + 1;
			if (arr[i][j] > bsq->size)
			{
				bsq->size = arr[i][j];
				bsq->x = i - bsq->size + 1;
				bsq->y = j - bsq->size + 1;
			}
		}
	}
}

void	print_bsq(t_map *map, t_sq *bsq)
{
	for (int i = bsq->x; i < bsq->x + bsq->size; i++)
	{
		for (int j = bsq->y; j < bsq->y + bsq->size; j++)
		{
			map->grid[i][j] = map->chars.full;
		}
	}
	for (int i = 0; i < map->hei; i++)
	{
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
	}
}

int	main(int ac, char **av)
{
	t_map	map;
	t_sq	bsq;
	FILE	*file;

	if (ac == 1)
	{
		if (read_map(stdin, &map))
			fprintf(stdout, "Error: invalid map\n");
		find_bsq(&map, &bsq);
		print_bsq(&map, &bsq);
		free_grid(&map);
	}
	else if (ac == 2)
	{
		file = fopen(av[1], "r");
		if (!file)
			fprintf(stdout, "Error: invalid map\n");
		if (read_map(file, &map))
		{
			fprintf(stdout, "Error: invalid map\n");
			fclose(file);
		}
		find_bsq(&map, &bsq);
		print_bsq(&map, &bsq);
		free_grid(&map);
		fclose(file);
	}
	else
	{
		fprintf(stdout, "Error: invalid map\n");
		return (1);
	}
	return (0);
}