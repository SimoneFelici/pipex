#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>

char	*get_path(char *cmd, char **envp);
void	manage_files(char *infile, char *outfile, int fds[2]);

#endif
