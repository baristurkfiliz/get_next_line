#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
char	*ft_read_and_create(int fd, char *str);
char	*ft_create(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str);
size_t	ft_strcpy(char	*dst, const char *src, size_t	dstsize);
void	*ft_free(void *str);
#endif