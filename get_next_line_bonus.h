#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef enum e_Bool{
	FALSE = 0,
	TRUE = 1
}	t_Bool;

char	*get_next_line(int fd);
t_Bool	ft_fill_buff(char *buff, int fd);
char	*ft_reset_buff(char *buff);
t_Bool	ft_check_line(char *line);
/*-------------------------UTILS-----------------------------*/
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_len_till_nl(const char *s);
void	ft_bzero(void *s, size_t n);

#endif
