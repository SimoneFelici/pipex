/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:12:54 by sfelici           #+#    #+#             */
/*   Updated: 2025/03/15 13:12:56 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		exit(127);
	}
	execve(path, args, envp);
	perror(args[0]);
	exit(126);
}

static void	fork_and_exec(t_vars *vars, int i)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit((perror("pipe"), 1));
	pid = fork();
	if (pid == -1)
		exit((perror("fork"), 1));
	if (pid == 0)
	{
		close(pipe_fd[0]);
		if (i == vars->argc - 2)
			execute_command(vars->argv[i], vars->envp, \
				vars->prev_fd, vars->outfile_fd);
		else
			execute_command(vars->argv[i], vars->envp, \
				vars->prev_fd, pipe_fd[1]);
	}
	close(pipe_fd[1]);
	if (vars->prev_fd != vars->infile_fd)
		close(vars->prev_fd);
	vars->prev_fd = pipe_fd[0];
}

static void	loop_commands(t_vars *vars)
{
	int	i;

	vars->prev_fd = vars->infile_fd;
	if (!ft_strncmp(vars->argv[1], "here_doc", 9))
		i = 3;
	else
		i = 2;
	while (i < vars->argc - 1)
	{
		fork_and_exec(vars, i);
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
	if (!strncmp(argv[1], "here_doc", 9))
	{
		here_doc(&vars);
	}
	else
		open_files(&vars);
	loop_commands(&vars);
	close(vars.infile_fd);
	close(vars.outfile_fd);
	while (wait(NULL) > 0)
		;
}
