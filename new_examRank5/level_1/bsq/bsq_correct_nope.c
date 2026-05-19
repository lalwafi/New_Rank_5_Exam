#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
    // info
	int n_lines;
	char empty;
	char obstacle;
	char full;

    // map
	char** grid;
	int width;
	int height;

    // square
	int size;
	int i;
	int j;
} t_map;

int loadElements(FILE* file, t_map* bsq)
{
	int ret = fscanf(file, "%d%c%c%c", &(bsq->n_lines), &(bsq->empty), &(bsq->obstacle), &(bsq->full));

	if((ret != 4))
		return(-1);

	if(bsq->n_lines <= 0)
		return(-1);
	if(bsq->empty == bsq->obstacle || bsq->empty == bsq->full || bsq->obstacle == bsq->full)
		return(-1);
	if(bsq->empty < 32 || bsq->empty > 126)
		return(-1);
	if(bsq->obstacle < 32 || bsq->obstacle > 126)
		return(-1);
	if(bsq->full < 32 || bsq->full > 126)
		return(-1);

    bsq->height = bsq->n_lines;
    bsq->width = 0;
    bsq->i = 0;
    bsq->j = 0;
    bsq->size = 0;
	return(0);
}

char* ft_substr(char* arr, int start, int len)
{
	char* str = (char*)malloc(len + 1);
	if (!str)
		return (NULL);
	int i = 0;
	int j = 0;
	while (arr[i])
	{
		if ((i >= start) && (j < len))
		{
			str[j] = arr[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return(str);
}

void free_map(char** arr)
{
	int	i = 0;
	if(arr)
	{
		while (arr[i] != NULL)
		{
			if(arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int loadMap(FILE* file, t_map* bsq)
{
	bsq->height = bsq->n_lines;
	bsq->grid = (char**)malloc((bsq->height + 1) * (sizeof(char *)));
	bsq->grid[bsq->height] = NULL;

	char* line = NULL;
	size_t len = 0;

	if(getline(&line, &len, file) == -1) {
		free_map(bsq->grid);
		return(-1);
	}

	for(int i = 0; i < bsq->height; i++)
	{
		int read = getline(&line, &len, file);
		if(read == -1) 
		{
			free(line);
			free_map(bsq->grid);
			return(-1);
		}
		if(line[read - 1] == '\n')
			read--;
		else
		{
			free(line);
			free_map(bsq->grid);
			return(-1);
		}
		bsq->grid[i] = ft_substr(line, 0, read);
		if(!(bsq->grid[i]))
		{
			free(line);
			free_map(bsq->grid);
			return(-1);
		}

		if(i == 0)
			bsq->width = read;
		else
		{
			if(bsq->width != read)
			{
				free(line);
				free_map(bsq->grid);
				return(-1);
			}
		}
	}
	free(line);

	return (0);
}

int find_min(int n1, int n2, int n3)
{
	int min = n1;

	if(n2 < min)
		min = n2;
	if(n3 < min)
		min = n3;
	return(min);
}

void find_big_square(t_map* bsq)
{
	// matrix init
	int matrix[bsq->height][bsq->width];

	for(int y = 0; y < bsq->height; y++)
	{
		for(int x = 0; x < bsq->width; x++)
		{
			if(bsq->grid[y][x] == bsq->obstacle)
				matrix[y][x] = 0;
			else if(y == 0 || x == 0)
				matrix[y][x] = 1;
			else {
				int min = find_min(matrix[y - 1][x],matrix[y - 1][x - 1], matrix[y][x - 1]);
				matrix[y][x] = min + 1;
			}

			if(matrix[y][x] > bsq->size)
			{
				bsq->size = matrix[y][x];
				bsq->i = y - matrix[y][x] + 1;
				bsq->j = x - matrix[y][x] + 1;
			}
		}
	}
}

void print_filled_square(t_map* bsq)
{

	for(int y = bsq->i; y < bsq->i + bsq->size; y++)
	{
		for(int x = bsq->j; x < bsq->j + bsq->size; x++)
		{
			if((y < bsq->height) && (x < bsq->width))
				bsq->grid[y][x] = bsq->full;
		}
	}

	for(int y = 0; y < bsq->height; y++)
		printf("%s\n", bsq->grid[y]);
}

int execute_bsq(FILE* file)
{
	t_map bsq;
	if(loadElements(file, &bsq) == -1)
		return(-1);

	if(loadMap(file, &bsq) == -1)
		return(-1);

	find_big_square(&bsq);
	print_filled_square(&bsq);
	free_map(bsq.grid);
	return(0);
}

int convert_file_pointer(char* name)
{
	FILE* file = fopen(name, "r");
	if(!file)
		return(-1);
	int ret = 0;
	ret = execute_bsq(file);
	fclose(file);
	return(ret);
}


int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		if(execute_bsq(stdin) == -1)
			printf("%s", "map error\n");
	}
	else
	{
		for(int i = 1; i < argc; i++)
        {
            if(convert_file_pointer(argv[i]) == -1)
                printf("%s", "map error\n");
            if(i < argc - 1)
                printf("%c", '\n');
        }
	}
	return(0);
}