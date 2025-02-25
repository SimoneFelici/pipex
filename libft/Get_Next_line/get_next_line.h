#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

char	*get_next_line(int fd);

char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);

#endif
