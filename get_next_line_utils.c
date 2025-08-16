#include "get_next_line.h"

static int	ft_now_newlen(char *str)
{
	int	i;

	i = 0;
	while (str)
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

int main()
{
	char *result = ft_get_line_from_leftover("Hello\nWorld");
	printf("%s", result);
}

