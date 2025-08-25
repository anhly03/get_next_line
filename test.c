// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/08/22 15:15:15 by phly              #+#    #+#             */
// /*   Updated: 2025/08/22 15:15:16 by phly             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// // static char	*extract_line(char *leftover)
// // {
// // 	int		pos;
// // 	char	*line;
// // 	char	*new_leftover;

// // 	pos = ft_find_newline(leftover);
// // 	if (pos == -1)
// // 		return (NULL);
// // 	line = ft_substr(leftover, 0, pos + 1);
// // 	new_leftover = ft_update_leftover(leftover);
// // 	return (line);
// // }

// // #include <stdio.h>

// // int main()
// // {
// // 	char *leftover = "Hello\nWorld";
// // 	int pos = ft_find_newline(leftover);
// // 	char *result = extract_line(leftover);
// // 	// char *result = ft_substr(leftover, 0, pos + 1);
// // 	// char *result = ft_update_leftover(leftover);
// // 	printf("%s", result);
// // }


// int main()
// {
//     char *result = ft_strdup("\n\n"); // có newline
//     char *leftover = ft_update_leftover(result);
//     if (leftover)
//     {
//         printf("%s\n", leftover);
//         free(leftover);
//     }
//     else
//     {
//         printf("NULL leftover\n");
//     }
//     return 0;
// }

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
		printf("%s\n", line); // mỗi lần gọi trả về 1 dòng
		free(line);
	}
	close(fd);
	return (0);
}
