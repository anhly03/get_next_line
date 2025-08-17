#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char		*get_next_line(int fd);
static int	ft_strlen(char *str);
int			ft_find_newline(char *str);
char		*ft_strdup(char *str);
char		*ft_get_line_from_leftover(char *str);
char		*ft_update_leftover(char *str);

#endif
