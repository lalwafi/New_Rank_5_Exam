#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int ac, char **av)
{
	if (ac != 4)
		return 1;

	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iter = atoi(av[3]);

	if (width <=0 || height <= 0 || iter < 0)
		return 1;
	
	int grid[height][width];
	int new_grid[height][width];
	
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
			grid[y][x] = 0;
	}
	
	char c;
	int y = 0, x = 0;
	bool pen = false;
	while (read(STDIN_FILENO, &c, 1))
	{
		if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < (width - 1))
			x++;
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < (height - 1))
			y++;
		else if (c == 'x')
			pen = !pen;
		
		if (pen == true)
			grid[y][x] = 1;
	}

	for (int i = 0; i < iter; i++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int neighbors = 0;
				for (int yy = -1; yy <= 1; yy++)
				{
					for (int xx = -1; xx <= 1; xx++)
					{
						if ((xx || yy) && (xx + x) >= 0 && (xx + x) < width &&\
							(yy + y) >= 0 && (yy + y) < height && grid[y+yy][x+xx] == 1)        // revise
								neighbors += 1;
					}
				}

				if (grid[y][x] == 1 && (neighbors == 2 || neighbors == 3))
					new_grid[y][x] = 1;
				else if (grid[y][x] == 0 && neighbors == 3)
					new_grid[y][x] = 1;
				else
					new_grid[y][x] = 0;
			}
		}
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
				grid[y][x] = new_grid[y][x];
		} 
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (grid[y][x] == 1)
				putchar('O');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
