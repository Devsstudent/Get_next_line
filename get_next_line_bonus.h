/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:06:23 by odessein          #+#    #+#             */
/*   Updated: 2022/05/30 18:40:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_bool{
	FALSE,
	TRUE
}	t_bool;

char	*get_next_line(int fd);
t_bool	ft_fill_buff(char *buff, int fd);
char	*ft_reset_buff(char *buff);
t_bool	ft_check_line(char *line);
char	*ft_loop(char *line, char *buff, int fd);
/*-------------------------UTILS-----------------------------*/
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_len_till_nl(const char *s);
void	ft_bzero(void *s, size_t n);

#endif
