/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:28:12 by phly              #+#    #+#             */
/*   Updated: 2025/08/28 18:18:07 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_find_newline(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0' && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*str_new;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	str_new = malloc((len + 1) * sizeof(char));
	if (!str_new)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new_str;


	i = 0;
	j = 0;
	// if (ft_strlen(s1))
	// 	s1 = ft_strdup("");
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

// char	*ft_substr(const char *str, size_t start, size_t len)
// {
// 	size_t	str_len;
// 	size_t	i;
// 	char	*sub_str;

// 	if (!str)
// 		return (NULL);
// 	str_len = ft_strlen(str);
// 	if (start >= str_len)
// 		return (ft_strdup(""));
// 	if (len > str_len - start)
// 		len = str_len - start;
// 	sub_str = malloc(len + 1);
// 	if (!sub_str)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		sub_str[i] = str[start + i];
// 		i++;
// 	}
// 	sub_str[i] = '\0';
// 	return (sub_str);
// }
