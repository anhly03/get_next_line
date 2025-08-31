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

void new_remain(char *remain, char *result)
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

static int check_read(int byte_reads, char *remain, char *buffer, char *result)
{
	if (byte_read == -1)
	{
		remain[0] = '\0';
		free (buffer);
		free (result);
		return (1);
	}
	return (0);
}

char	*read_until_nextline(int fd, char *remain)
{
	char	*buffer;
	int		byte_reads;
	char	*temp;
	char	*result;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	result = init_remain(remain);
	if (!result)
		return (free(buffer), NULL);
	byte_reads = 1;
	while (!ft_strchr(result, '\n') && byte_reads != 0)
	{
		byte_reads = read(fd, buffer, BUFFER_SIZE);
		if (check_read(byte_reads, remain, buffer, result) == 1)
			return (NULL);
		buffer[byte_reads] = '\0';
		temp = result;
		result = ft_strjoin(temp, buffer);
		free(temp);
		if (!result)
			return (free(buffer), NULL);
		rerturn (free(buffer), new_remain(remain, result), result);
	}	
}


char	*ft_get_line_from_leftover(char *str)
{
	int		i;
	int		pos;
	char	*s1;

	if (!str)
		return (NULL);
	i = 0;
	pos = ft_find_newline(str);
	if (pos == -1)
		return (ft_strdup(str));
	s1 = malloc((pos + 2) * sizeof(char));
	if (!s1)
		return (NULL);
	while (i < pos + 1)
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
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
	if (pos == -1)
		return (NULL);
	start = pos + 1;
	if (start >= ft_strlen(str))
		return (NULL);
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

	// if (!*leftover)
	// 	return (NULL);
	// if (*leftover[0] == '\0')
	// {
	// 	// free (*leftover);
	// 	*leftover = NULL;
	// 	return (NULL);
	// }
	returned_line = *leftover;
	*leftover = NULL;
	return (returned_line);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*leftover = NULL;
	int				byte_read;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	while (1)
	{
		if (ft_find_newline(leftover) != -1)
		{
			free(buffer);
			return (ft_extractline(&leftover));
		}
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// if (byte_read == 1 && ft_strlen(buffer) == 0)
		// 	return (NULL);
		// if (byte_read == 1 && buffer[byte_read] == '\0')
		// 	return (NULL);
		// if (byte_read == 1 && leftover == NULL)
		// 	return (NULL);
		if (byte_read == 0)
		{
			free(buffer);
			return (ft_return_leftover_at_eof(&leftover));
		}
		temp = leftover;
		leftover = ft_strjoin(leftover, buffer);
		free(temp);
	}
}
