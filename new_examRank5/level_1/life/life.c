#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	
	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iter = atoi(av[3]);

	if (height <= 0 || width <= 0 || iter < 0)
		return 1;
	
	char board[height][width];
	char new_board[height][width];

	// fill board with empty cells
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			board[i][j] = 0;
	}

	// do the wasd shit to fill board
	char c;
	bool pen = false;
	int x = 0;
	int y = 0;
	while (read(STDIN_FILENO, &c, 1))
	{
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < (height - 1))
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < (width - 1))
			x++;
		else if (c == 'x')
			pen = !pen;
		
		if (pen)
			board[y][x] = 1;
	}

	// iterations
	for (int i = 0; i < iter; i++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// check how many alive neighbors, we store those in density
				int density = 0;
				for (int yy = -1; yy <= 1; yy++)
				{
					for (int xx = -1; xx <= 1; xx++)
					{
						if ((xx || yy) && (x + xx) >= 0 && (x + xx) < width &&\
							(y + yy) >= 0 && (y + yy) < height)
							density += board[y + yy][x + xx];
					}
				}
				if (board[y][x] == 1 && (density == 2 || density == 3))
					new_board[y][x] = 1;
				else if (board[y][x] == 0 && density == 3)
					new_board[y][x] = 1;
				else
					new_board[y][x] = 0;
			}
		}
		
		// stores the last iterations before moving to next iteration
		for (int rows = 0; rows < height; rows++)
		{
			for (int cols = 0; cols < width; cols++)
				board[rows][cols] = new_board[rows][cols];
		}
	}

	// print the final iteration of game of life
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == 1)
				putchar('O');
			else
				putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}
