#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int err(char *str)
{
	int i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	return (1);
}

int cd(char **av, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	if (chdir(av[1]) == -1)
		return (err("error: cd: cannot change directory to "), err(av[1]), err("\n"));
	return (0);
}

int exec(char **av, char **env, int i)
{
	int fd[2];
	int status = 0;
	int has_pipe = 0;

	if (av[i] && strcmp(av[i], "|") == 0)
		has_pipe = 1;
	
	if (has_pipe == 1 && pipe(fd) == -1)
		return (err("error: fatal"));
	
	int pid = fork();
	if (pid == 0)
	{
		av[i] = 0;
		if (has_pipe == 1 && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
			return (err("error: fatal"));
		execve(*av, av, env);
		return (err("error: cannot execute "), err(*av), err("\n"));
	}

	waitpid(pid, &status, 0);
	if (has_pipe == 1 && (dup2(fd[0], 0) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
		return (err("error: fatal"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	int status = 0;

	if (ac > 1)
	{
		while (av[i] && av[++i])
		{
			av += i;
			i = 0;
			while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
				i++;
			if (strcmp(*av, "cd") == 0)
				status = cd(av, i);
			else if (i != 0)
				status = exec(av, env, i);
		}
	}
	return (status);
}