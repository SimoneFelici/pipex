#include "get_next_line.h"

static char	*reader(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	int		newline_index;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	newline_index = gnl_strchr(stash, '\n');
	while (newline_index < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		newline_index = gnl_strchr(stash, '\n');
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		newline_index;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	newline_index = gnl_strchr(stash, '\n');
	if (newline_index < 0)
		newline_index = gnl_strlen(stash) - 1;
	line = (char *)malloc(sizeof(char) * (newline_index + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i <= newline_index)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*cleaner(char *stash)
{
	char	*new_stash;
	int		newline_index;
	int		s_len;
	int		i;

	newline_index = gnl_strchr(stash, '\n');
	if (newline_index < 0)
	{
		free(stash);
		return (NULL);
	}
	s_len = gnl_strlen(stash);
	new_stash = (char *)malloc(sizeof(char) * (s_len - newline_index));
	if (!new_stash)
		return (NULL);
	i = 0;
	while (stash[newline_index + 1 + i])
	{
		new_stash[i] = stash[newline_index + 1 + i];
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = reader(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = cleaner(stash);
	return (line);
}
