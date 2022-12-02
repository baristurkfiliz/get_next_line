#include <stdio.h>
#include "get_next_line.h"

char	*ft_get_line(char	*str)
{
	int	i;
	char	*string;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	string = malloc(sizeof(char) * (i + 2));
	if (!string)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		string[i] = str[i];
	if (str[i] == '\n')
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);

}

char	*ft_create(char *str)
{
	int	i;
	int	j;
	char	*string;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	string = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!string)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		string[j++] = str[i++];
	string[j] = '\0';
	free(str);
	return (string);
}

char	*ft_reader(int	fd, char *str)
{
	char	*buff;
	int		rc;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rc = 1;
	while (!ft_strchr(str) && rc != 0)
	{
		rc = read(fd, buff, BUFFER_SIZE);
		if (rc == -1)
			return (ft_free(buff));
		buff[rc] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_reader(fd, str);
	if (!str)
		return(0);
	line = ft_get_line(str);
	str	= ft_create(str);
	return (line);
}

#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open("asd", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return 0;
}