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

void	new_leftover(char *remain, char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!remain || !result)
		return ;
	while (result[i] && result[i] != '\n')
		i++;
	if (!result[i] || !result[i + 1])
	{
		remain[0] = '\0';
		return ;
	}
	i++;
	while (result[i] && j < BUFFER_SIZE)
		remain[j++] = result[i++];
	remain[j] = '\0';
}

static char	*init_remain(char *remain)
{
	if (remain && remain[0] != '\0')
		return (ft_strdup(remain));
	return (ft_strdup(""));
}

static int	check_read(int byte_reads, char *leftover,
		char *buffer, char *result)
{
	if (byte_reads == -1)
	{
		leftover[0] = '\0';
		free (buffer);
		free (result);
		return (1);
	}
	return (0);
}

char	*read_until_nextline(int fd, char *remain)
{
	char	*buffer;
	int		read_bytes;
	char	*temp;
	char	*result;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	result = init_remain(remain);
	if (!result)
		return (free(buffer), NULL);
	read_bytes = 1;
	while (!ft_find_newline(result, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (check_read(read_bytes, remain, buffer, result) == 1)
			return (NULL);
		buffer[read_bytes] = '\0';
		temp = result;
		result = ft_strjoin(temp, buffer);
		free(temp);
		if (!result)
			return (free(buffer), NULL);
	}
	return (free(buffer), new_leftover(remain, result), result);
}

char	*get_next_line(int fd)
{
	static char	remain[BUFFER_SIZE + 1];
	char		*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_until_nextline(fd, remain);
	if (!buffer)
		return (NULL);
	next_line = returned_line(buffer);
	if (!next_line)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (next_line);
}
