/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:28:12 by phly              #+#    #+#             */
/*   Updated: 2025/09/04 17:19:28 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_find_newline(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*str_new;

	if (!str)
		return (NULL);
	str_new = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!str_new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len_s1;
	size_t		len_s2;
	char		*new_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < len_s1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*returned_line(char *buffer)
{
	char	*line;
	int		i;
	int		len;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
