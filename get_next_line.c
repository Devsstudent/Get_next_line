#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	char *line;

	line = (char *) malloc(sizeof(*line));
	*line = 0;
	if (*buff != 0)
		line = ft_strjoin(line, buff);
	if (ft_check_line(line))
		ft_reset_buff(buff);
	while (!ft_check_line(line))
	{
		if (!ft_fill_buff(buff, fd))
		{
			free(line);
			return (NULL);
		}
		ft_get_line(buff, &line);
	}
	return (line);
}

t_Bool	ft_fill_buff(char *buff, int fd)
{
	int	read_val;

	read_val = read(fd, buff, BUFFER_SIZE);
	if (read_val > 0)
	{
		buff[read_val] = 0;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_get_line(char *buff, char **line)
{
	*line = ft_strjoin(*line, buff); //Avec un join modifier qui s'arrete au \n et free
	buff = ft_reset_buff(buff);
}

t_Bool	ft_check_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (TRUE);
		line++;
	}
	return (FALSE);
}

char	*ft_reset_buff(char *buff)
{
	int	i;
	char	*new_buff;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	new_buff = ft_strdup(&buff[i]);
	if (!new_buff)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE);
	i = 0;
	while (new_buff[i])
	{
		buff[i] = new_buff[i];
		i++;
	}
	free(new_buff);
	return buff;
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char *x;

	fd = open("test", O_RDONLY);
	while (x = get_next_line(fd))
	{
		printf("%s", x);
		free(x);
	}
}
*/
