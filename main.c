#include "pipex.h"

int main(int argc, char **argv)
{
	int file1;
	int file2;
	pid_t pid;

	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pid = fork();

	if (pid == 0)
	{
		dup2(file1, STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		close(file1);
		close(file2);

		char **args = ft_split(argv[2], ' ');
		char *path = "/usr/bin/grep";
		execve(path, args, NULL);        
		exit(1);
	}

	close(file1);
	close(file2);
	waitpid(pid, NULL, 0);
	return (0);
}