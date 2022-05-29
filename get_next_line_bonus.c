#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char buff[1024][BUFFER_SIZE + 1];
	char *line;

	line = (char *) malloc(sizeof(*line));
	*line = 0;
	if (*buff != 0)
		line = ft_strjoin(line, buff[fd]);
	if (ft_check_line(line))
		ft_reset_buff(buff[fd]);
	while (!ft_check_line(line))
	{
		if (!ft_fill_buff(buff[fd], fd))
		{
			if (*line == 0)
				free(line);
			else
			{
				ft_reset_buff(buff[fd]);
				return (line);
			}
			return (NULL);
		}
		line = ft_strjoin(line, buff[fd]); //Avec un join modifier qui s'arrete au \n et free
		ft_reset_buff(buff[fd]);
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

t_Bool	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (TRUE);
		i++;
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
	new_buff = ft_strdup(&(buff[i]));
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
	return (buff);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char *x;

	fd = open("files/41_with_nl", O_RDONLY);
	while (x = get_next_line(fd))
	{
		printf("%s", x);
		free(x);
	}
}*/
