#include "pipex.h"

static void execute_command(char *cmd, char **envp, int input_fd, int output_fd)
{
	char **args;
	char *path;

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

static void loop_commands(int argc, char **argv, char **envp, int infile_fd, int outfile_fd)
{
	int fd[2];
	int i;
	int prev_fd;

	prev_fd = infile_fd;
	i = 2;
	while (i < argc - 1)
	{
		pipe(fd);
		pid_t pid = fork();

		if (pid == 0)
		{
			if (i == argc - 2)
				execute_command(argv[i], envp, prev_fd, outfile_fd);
			else
				execute_command(argv[i], envp, prev_fd, fd[1]);
		}
		close(fd[1]);
		if (prev_fd != infile_fd)
			close(prev_fd);
		prev_fd = fd[0];
		i++;
	}
	close(prev_fd);
}

int main(int argc, char **argv, char **envp)
{
	int infile_fd;
	int outfile_fd;

	if (argc != 5)
		return (1);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
	{
		perror(argv[1]);
		exit(1);
	}
	outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile_fd < 0)
	{
		perror(argv[4]);
		exit(1);
	}
	loop_commands(argc, argv, envp, infile_fd, outfile_fd);
	close(infile_fd);
	close(outfile_fd);
	while (wait(NULL) > 0);
	return (0);
}
