/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:28:12 by phly              #+#    #+#             */
/*   Updated: 2025/08/18 21:28:12 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_newline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*str_new;
	size_t	len;

	len = ft_strlen(str);
	str_new = malloc((len + 1) * sizeof(char));
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		s1 = ft_strdup("");
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	size_t	str_len;
	size_t	actual_len;
	char	*sub_str;
	size_t	i;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	actual_len = str_len - start;
	if (len > actual_len)
		len = actual_len;
	sub_str = malloc((actual_len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len && str[start])
		sub_str[i++] = str[start++];
	sub_str[i] = '\0';
	return (sub_str);
}

// size_t main()
// {
//     char *leftover = ft_strdup("Hello\nWorld\nThis is a test\n");
//     char *line;

//     while (leftover) // còn leftover mới đọc tiếp
//     {
//         line = ft_get_line_from_leftover(leftover);
//         prsize_tf("Line: %s", line); // nhớ line đã có '\n' nếu có
//         free(line);

//         leftover = ft_update_leftover(leftover);
//     }

//     return 0;
// }