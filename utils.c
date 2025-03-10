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

void	manage_files(char *infile, char *outfile, int fds[2])
{
	fds[0] = open(infile, O_RDONLY);
	if (fds[0] < 0)
	{
		perror(infile);
		fds[0] = open("/dev/null", O_RDONLY);
		if (fds[0] < 0)
		{
			perror("/dev/null");
			exit(1);
		}
	}
	fds[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds[1] < 0)
	{
		perror(outfile);
		close(fds[0]);
		exit(1);
	}
}
