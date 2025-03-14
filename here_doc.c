#include "pipex.h"

void	here_doc_input(char *limiter, int output_fd)
{
	char	*line;

	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strncmp(line, limiter, ft_strlen(limiter))
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(output_fd, line, ft_strlen(line));
		free(line);
	}
	close(output_fd);
}

void	here_doc(t_vars *vars)
{
	int	tmp_fd;

	tmp_fd = open("/tmp/pipex_here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
	{
		perror("here_doc");
		exit(EXIT_FAILURE);
	}
	here_doc_input(vars->argv[2], tmp_fd);
	close(tmp_fd);
	vars->infile_fd = open("/tmp/pipex_here_doc", O_RDONLY);
	if (vars->infile_fd < 0)
	{
		perror("/tmp/pipex_here_doc");
		exit(EXIT_FAILURE);
	}
	unlink("/tmp/pipex_here_doc");
	vars->outfile_fd = open(vars->argv[vars->argc - 1], \
		O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (vars->outfile_fd < 0)
	{
		perror(vars->argv[vars->argc - 1]);
		exit(EXIT_FAILURE);
	}
}
