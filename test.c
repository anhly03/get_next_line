/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:04:44 by phly              #+#    #+#             */
/*   Updated: 2025/08/28 16:19:47 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <stdio.h>

// int main ()
// {
// 	char *result = "Phi\n\nAnh";
// 	printf("%s", ft_get_line_from_leftover(result));
// 	return 0;
// }

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

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int count = 1;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: [%s]\n", count, line);
        free(line); // nhớ free mỗi line sau khi dùng
        count++;
    }

    printf("EOF reached: get_next_line returned NULL\n");
    close(fd);
    return (0);
}

