/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:12:27 by sfelici           #+#    #+#             */
/*   Updated: 2025/03/15 13:12:28 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}	t_vars;

char	*get_path(char *cmd, char **envp);
void	open_files(t_vars *vars);
void	here_doc(t_vars *vars);
void	here_doc_input(char *limiter, int output_fd);
void	open_here_doc(t_vars *vars);

#endif
