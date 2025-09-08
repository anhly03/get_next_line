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

void	new_leftover(char *new_leftover, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!new_leftover || !line)
		return ;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
	{
		new_leftover[0] = '\0';
		return ;
	}
	i++;
	while (line[i] && j < BUFFER_SIZE)
		new_leftover[j++] = line[i++];
	leftover[j] = '\0';
}

static char	*init_leftover(char *leftover)
{
	if (leftover && leftover[0] != '\0')
		return (ft_strdup(leftover));
	return (ft_strdup(""));
}

static int	check_read(int byte_reads, char *leftover,
		char *buffer, char *returned_line)
{
	if (byte_reads == -1)
	{
		leftover[0] = '\0';
		free (buffer);
		free (returned_line);
		return (1);
	}
	return (0);
}

char	*read_until_nextline(int fd, char *leftover)
{
	char	*buffer;
	int		read_bytes;
	char	*temp;
	char	*returned_line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	returned_line = init_leftover(leftover);
	if (!returned_line)
		return (free(buffer), NULL);
	read_bytes = 1;
	while (!ft_find_newline(returned_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (check_read(read_bytes, leftover, buffer, returned_line) == 1)
			return (NULL);
		buffer[read_bytes] = '\0';
		temp = returned_line;
		returned_line = ft_strjoin(temp, buffer);
		free(temp);
		if (!returned_line)
			return (free(buffer), NULL);
	}
	return (free(buffer), new_leftover(leftover, returned_line), returned_line);
}

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_until_nextline(fd, leftover);
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


