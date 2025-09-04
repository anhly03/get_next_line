/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:08:49 by phly              #+#    #+#             */
/*   Updated: 2025/08/18 22:08:49 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

size_t		ft_strlen(const char *str);
char		*ft_find_newline(const char *str, int c);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
char		*returned_line(char *buffer);
void		new_leftover(char *remain, char *result);
char		*read_until_nextline(int fd, char *remain);
char		*get_next_line(int fd);

#endif
