#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_vars
{
	int	i;
	int fd;
	int pfd[2];
}	t_vars;

void	ft_putstr_fd2(char *msg, char *arg)
{
	while (*msg)
		write(2, msg++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
}

void	ft_execute(char *av[], char *env[], t_vars *vars)
{
	av[vars->i] = NULL;
	dup2(vars->fd, STDIN_FILENO);
	close (vars->fd);
	execve(av[0], av, env);
	ft_putstr_fd2("error: cannot execute ", av[0]);
	exit (1);
}

void	handle_cd(char *av[], t_vars *vars)
{
	if (vars->i != 2)
		ft_putstr_fd2("error: cd: bad arguments", NULL);
	else if (chdir(av[1]) != 0)
		ft_putstr_fd2("error: cd: cannot change directory to ", av[1]);
}

void	handle_last_cmd(char *av[], char *env[], t_vars *vars)
{
	if (fork() == 0)
		ft_execute(av, env, vars);
	else
	{
		close (vars->fd);
		while (waitpid(-1, NULL, WUNTRACED) != -1)
			;
		vars->fd = dup(STDIN_FILENO);
	}
}

void	handle_pipe(char *av[], char *env[], t_vars *vars)
{
	pipe(vars->pfd);
	if (fork() == 0)
	{
		dup2(vars->pfd[1], STDOUT_FILENO);
		close (vars->pfd[0]);
		close (vars->pfd[1]);
		ft_execute(av, env, vars);
	}
	else
	{
		close(vars->pfd[1]);
		close (vars->fd);
		vars->fd = vars->pfd[0];
	}
}

int main(int ac, char *av[], char *env[])
{
	t_vars	vars;

	(void)ac;
	vars.i = 0;
	vars.fd = dup(STDIN_FILENO);
	while (av[vars.i] && av[vars.i + 1])
	{
		av = &av[vars.i + 1];
		vars.i = 0;
		while (av[vars.i] && strcmp(av[vars.i], ";") && strcmp(av[vars.i], "|"))
			vars.i++;
		if (strcmp(av[0], "cd") == 0)
			handle_cd(av, &vars);
		else if (vars.i != 0 && (av[vars.i] == NULL || strcmp(av[vars.i], ";") == 0))
			handle_last_cmd(av, env, &vars);
		else if (vars.i != 0 && strcmp(av[vars.i], "|") == 0)
			handle_pipe(av, env, &vars);
	}
	close (vars.fd);
	return (0);
}
