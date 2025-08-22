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

	pos = ft_find_newline(str);
	start = pos + 1;
	if (pos == -1 || str[start] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_leftover = malloc((ft_strlen(str) - start + 1) * sizeof(char));
	if (!new_leftover)
		return (NULL);
	i = 0;
	while (str[start] != '\0')
		new_leftover[i++] = str[start++];
	free(str);
	new_leftover[i] = '\0';
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line_to_return;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		pos = ft_find_newline(leftover);
		if (pos != -1)
		{
			line_to_return = ft_substr(leftover, 0, pos + 1);
			leftover = ft_update_leftover(leftover);
			return (line_to_return);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
		{
			line_to_return = leftover;
			leftover = NULL;
			return (line_to_return);
		}
		buffer[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buffer);
	}
}

#include <fcntl.h>   // open()
#include <stdio.h>   // printf()

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // mỗi lần gọi trả về 1 dòng
        free(line);
    }
    close(fd);
    return (0);
}
