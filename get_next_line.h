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
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char		*get_next_line(int fd);
int			ft_strlen(char *str);
int			ft_find_newline(char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *str, size_t start, size_t len);
char		*ft_get_line_from_leftover(char *str);
char		*ft_update_leftover(char *str);
static char	*extract_line(char *leftover);

#endif
