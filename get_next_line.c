/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:18:57 by odessein          #+#    #+#             */
/*   Updated: 2022/05/30 18:41:00 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	line = (char *) malloc(sizeof(*line));
	if (!line)
		return (NULL);
	*line = 0;
	if (*buff != 0)
		line = ft_strjoin(line, buff);
	if (ft_check_line(line))
		ft_reset_buff(buff);
	line = ft_loop(line, buff, fd);
	return (line);
}

char	*ft_loop(char *line, char *buff, int fd)
{
	while (!ft_check_line(line))
	{
		if (!ft_fill_buff(buff, fd))
		{
			if (*line == 0)
				free(line);
			else
			{
				ft_reset_buff(buff);
				return (line);
			}
			return (NULL);
		}
		line = ft_strjoin(line, buff);
		ft_reset_buff(buff);
	}
	return (line);
}

t_bool	ft_fill_buff(char *buff, int fd)
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

t_bool	ft_check_line(char *line)
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
	int		i;
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
	return (buff);
}
