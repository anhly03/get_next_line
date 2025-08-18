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
	ssize_t		bytes_read;
	char		*line_to_return;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	pos = ft_find_newline(buffer);
	while (pos != -1)
	{
		line_to_return = ft_get_line_from_leftover(buffer);
		leftover = ft_update_leftover(buffer);
	}
}

// function get_next_line(fd):
// 	static leftover = NULL   // giữ phần dư từ lần trước
// 	if fd < 0 or BUFFER_SIZE <= 0:
// 		return NULL
// 	while true:
// 		if leftover có chứa '\n':
// 			// Tìm vị trí \n
// 			// Cắt từ đầu đến \n => line_to_return
// 			// Phần sau \n => cập nhật leftover
// 			return line_to_return

// 		// Nếu không có \n, đọc thêm dữ liệu
// 		bytes_read = read(fd, buffer, BUFFER_SIZE)
// 		if bytes_read == -1:
// 			// Lỗi khi đọc
// 			return NULL

// 		if bytes_read == 0:
// 			// Hết file
// 			if leftover không rỗng:
// 				line_to_return = leftover
// 				leftover = NULL
// 				return line_to_return
// 			else:
// 				return NULL

// 		// Ghép buffer vừa đọc vào leftover
// 		leftover = leftover + buffer
