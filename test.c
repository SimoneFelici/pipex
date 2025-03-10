#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		file1, file2;
	char	*path;
	char	**args;
	if (argc != 4)
		return (1);

	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file1 < 0 || file2 < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(file1, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	args = ft_split(argv[2], ' ');
	path = get_path(args[0], envp);
	execve(path, args, envp);
}
