#include "pipex.h"

static char	*find_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp;
	char	*path_env;
	int		i;

	path_env = find_env_path(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	open_files(t_vars *vars)
{
	vars->infile_fd = open(vars->argv[1], O_RDONLY);
	if (vars->infile_fd < 0)
	{
		perror(vars->argv[1]);
		vars->infile_fd = open("/dev/null", O_RDONLY);
		if (vars->infile_fd < 0)
		{
			perror("open /dev/null");
			exit(1);
		}
	}
	vars->outfile_fd = open(vars->argv[vars->argc - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->outfile_fd < 0)
	{
		perror(vars->argv[vars->argc - 1]);
		close(vars->infile_fd);
		exit(1);
	}
}
