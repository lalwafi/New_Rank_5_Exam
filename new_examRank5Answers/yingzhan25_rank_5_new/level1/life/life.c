#include "life.h"

static void	free_grid(char **grid, int num)
{
	if (grid)
	{
		for (int i = 0; i < num; i++)
			free(grid[i]);
		free(grid);
	}
}

static char**	init_grid(t_game *game, int flag)
{
	char	**grid;

	grid = malloc(game->hei * sizeof(char*));
	if (!grid)
		return (NULL);
	for (int i = 0; i < game->hei; i++)
	{
		grid[i] = malloc(game->wid * sizeof(char));
		if (!grid[i])
		{
			free_grid(grid, i);
			return (NULL);
		}
		for (int j = 0; j < game->wid; j++)
		{
			if (!flag)
				grid[i][j] = ' ';
			else
				grid[i][j] = game->grid[i][j];
		}
	}
	return (grid);
}

static int	init_game(t_game *game, char **av)
{
	game->wid = atoi(av[1]);
	game->hei = atoi(av[2]);
	game->ite = atoi(av[3]);
	game->x = 0;
	game->y = 0;
	game->draw = -1;
	game->grid = init_grid(game, 0);
	if (!game->grid)
		return (1);
	return (0);
}

static void	fill_grid(t_game *game)
{
	char	buf;
	int		x = game->x;
	int		y = game->y;

	while (read(STDIN_FILENO, &buf, 1))
	{
		if (buf == 'a' && y > 0)
			y -= 1;
		else if (buf == 'd' && y < game->wid -1)
			y += 1;
		else if (buf == 'w' && x > 0)
			x -= 1;
		else if (buf == 's' && x < game->hei -1)
			x += 1;
		else if (buf == 'x')
			game->draw *= -1;
		else
			continue ;
		if (game->draw == 1)
			game->grid[x][y] = '0';
	}
}

static int	should_alive(t_game *game, char **tmp, int i, int j)
{
	int	count = 0;
	for (int k = -1; k < 2; k++)
	{
		for (int l = -1; l < 2; l++)
		{
			if (i + k >= 0 && j + l >=0 && i + k < game->wid && j + l < game->hei && !(k == 0 && l == 0) && tmp[i + k][j + l] == '0')
				count++;
		}
	}
	if (tmp[i][j] == '0' && (count == 2 || count == 3))
		return (1);
	else if (tmp[i][j] == ' ' && count == 3)
		return (1);
	else
		return (0);
}

static int	iter_grid(t_game *game)
{
	char	**tmp;
	tmp = init_grid(game, 1);
	if (!tmp)
		return (1);
	for (int i = 0; i < game->hei; i++)
	{
		for (int j = 0; j < game->wid; j++)
		{
			if (should_alive(game, tmp, i, j))
				game->grid[i][j] = '0';
			else
				game->grid[i][j] = ' ';
		}
	}
	free_grid(tmp, game->hei);
	return (0);
}

static void	print_grid(t_game *game)
{
	for (int i = 0; i < game->hei; i++)
	{
		for (int j = 0; j < game->wid; j++)
			putchar(game->grid[i][j]);
		putchar('\n');
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 4)
		return (1);
	if (init_game(&game, av))
		return (1);
	fill_grid(&game);
	for (int i = 0; i < game.ite; i++)
	{
		if (iter_grid(&game))
			return (1);
	}
	print_grid(&game);
	free_grid(game.grid, game.hei);
	return (0);
}