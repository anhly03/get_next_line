/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:28:17 by phly              #+#    #+#             */
/*   Updated: 2025/08/18 21:28:17 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line_from_leftover(char *str)
{
	int		i;
	int		pos;
	char	*s1;

	i = 0;
	pos = ft_find_newline(str);
	if (pos == -1)
	{
		s1 = ft_strdup(str);
		return (s1);
	}
	else
	{
		s1 = malloc((pos + 2) * sizeof(char));
		if (!s1)
			return (NULL);
		while (i < pos + 1)
		{
			s1[i] = str[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}

char	*ft_update_leftover(char *str)
{
	char	*new_leftover;
	int		pos;
	int		start;
	int		i;

	if (!str)
		return (NULL);
	pos = ft_find_newline(str);
	if (pos == -1 || str[0] == '\0')
		return (NULL);
	start = pos + 1;
	new_leftover = malloc((ft_strlen(str) - start + 1) * sizeof(char));
	if (!new_leftover)
		return (NULL);
	i = 0;
	while (str[start] != '\0')
		new_leftover[i++] = str[start++];
	new_leftover[i] = '\0';
	return (new_leftover);
}

char	*ft_extractline(char **leftover)
{
	char	*returned_line;
	char	*temp;

	returned_line = ft_get_line_from_leftover(*leftover);
	temp = *leftover;
	*leftover = ft_update_leftover(*leftover);
	free (temp);
	return (returned_line);
}

char	*ft_return_leftover_at_eof(char **leftover)
{
	char	*returned_line;

	if (!*leftover)
		return (NULL);
	returned_line = *leftover;
	*leftover = NULL;
	return (returned_line);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*leftover;
	int				byte_read;
	char			*returned_line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (ft_find_newline(leftover) != -1)
			return (ft_extractline(&leftover));
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		if (byte_read == 0)
			return (ft_return_leftover_at_eof(&leftover));
		buffer[byte_read] = '\0';
		temp = leftover;
		leftover = ft_strjoin(leftover, buffer);
		free(temp);
	}
	return (returned_line);
}






