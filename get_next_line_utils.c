#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_newline(const char *str)
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

char	*ft_strdup(const char *str)
{
	int		i;
	char	*str_new;
	int		len;

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	int		i;
	int		j;

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

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	actual_len;
	char	*sub_str;
	int		i;

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

// char	*ft_get_line_from_leftover(char *str)
// {
// 	int		i;
// 	int		pos;
// 	char	*s1;

// 	i = 0;
// 	pos = ft_find_newline(str);
// 	if (pos == -1)
// 	{
// 		s1 = ft_strdup(str);
// 		return (s1);
// 	}
// 	else
// 	{
// 		s1 = malloc((pos + 2) * sizeof(char));
// 		if (!s1)
// 			return (NULL);
// 		while (i < pos + 1)
// 		{
// 			s1[i] = str[i];
// 			i++;
// 		}
// 		s1[i] = '\0';
// 	}
// 	return (s1);
// }

// char	*ft_update_leftover(char *str)
// {
// 	char	*new_leftover;
// 	int		pos;
// 	int		start;
// 	int		i;

// 	pos = ft_find_newline(str);
// 	if (pos == -1)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	start = pos + 1;
// 	if (str[start] == '\0')
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	new_leftover = malloc((ft_strlen(str) - start + 1) * sizeof(char));
// 	if (!new_leftover)
// 		return (NULL);
// 	i = 0;
// 	while (str[start] != '\0')
// 		new_leftover[i++] = str[start++];
// 	free(str);
// 	new_leftover[i] = '\0';
// 	return (new_leftover);
// }

// int main()
// {
//     char *leftover = ft_strdup("Hello\nWorld\nThis is a test\n");
//     char *line;

//     while (leftover) // còn leftover mới đọc tiếp
//     {
//         line = ft_get_line_from_leftover(leftover);
//         printf("Line: %s", line); // nhớ line đã có '\n' nếu có
//         free(line);

//         leftover = ft_update_leftover(leftover);
//     }

//     return 0;
// }


