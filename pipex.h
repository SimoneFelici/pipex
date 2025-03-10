#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_vars
{
	int		infile_fd;
	int		outfile_fd;
	int		prev_fd;
	int		pipe_fd[2];
	int		fds[2];
	char	**envp;
	char	**argv;
	int		argc;
} t_vars;

char	*get_path(char *cmd, char **envp);
void	open_files(t_vars *vars);

#endif
