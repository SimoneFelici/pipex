#include "pipex.h"

static void	execute_command(char *cmd, char **envp, int input_fd, int output_fd)
{
	char	**args;
	char	*path;

	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(input_fd);
	close(output_fd);
	args = ft_split(cmd, ' ');
	path = get_path(args[0], envp);
	if (!path)
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(1);
	}
	execve(path, args, envp);
	perror("execve");
	exit(1);
}

static void	loop_commands(t_vars *vars)
{
	int		i;
	pid_t	pid;

	vars->prev_fd = vars->infile_fd;
	i = 2;
	while (i < vars->argc - 1)
	{
		pipe(vars->pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			if (i == vars->argc - 2)
				execute_command(vars->argv[i], vars->envp, \
					vars->prev_fd, vars->outfile_fd);
			else
				execute_command(vars->argv[i], vars->envp, \
					vars->prev_fd, vars->pipe_fd[1]);
		}
		close(vars->pipe_fd[1]);
		if (vars->prev_fd != vars->infile_fd)
			close(vars->prev_fd);
		vars->prev_fd = vars->pipe_fd[0];
		i++;
	}
	close(vars->prev_fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc < 5)
		return (1);
	vars.argc = argc;
	vars.argv = argv;
	vars.envp = envp;
	open_files(&vars);
	loop_commands(&vars);
	close(vars.infile_fd);
	close(vars.outfile_fd);
	while (wait(NULL) > 0)
		;
	return (0);
}
