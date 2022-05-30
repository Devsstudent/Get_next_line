/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:07:02 by odessein          #+#    #+#             */
/*   Updated: 2022/05/30 17:07:05 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef enum e_bool{
	FALSE,
	TRUE
}	t_bool;

char	*get_next_line(int fd);
t_bool	ft_fill_buff(char *buff, int fd);
void	ft_get_line(char *buff, char **line);
t_bool	ft_check_line(char *line);
char	*ft_reset_buff(char *buff);
char	*ft_loop(char *line, char *buff, int fd);
/*-------------------------UTILS-----------------------------*/
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_len_till_nl(const char *s);
void	ft_bzero(void *s, size_t n);

#endif
