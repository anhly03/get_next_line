/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:15:15 by phly              #+#    #+#             */
/*   Updated: 2025/08/22 15:15:16 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// static char	*extract_line(char *leftover)
// {
// 	int		pos;
// 	char	*line;
// 	char	*new_leftover;

// 	pos = ft_find_newline(leftover);
// 	if (pos == -1)
// 		return (NULL);
// 	line = ft_substr(leftover, 0, pos + 1);
// 	new_leftover = ft_update_leftover(leftover);
// 	return (line);
// }

// #include <stdio.h>

// int main()
// {
// 	char *leftover = "Hello\nWorld";
// 	int pos = ft_find_newline(leftover);
// 	char *result = extract_line(leftover);
// 	// char *result = ft_substr(leftover, 0, pos + 1);
// 	// char *result = ft_update_leftover(leftover);
// 	printf("%s", result);
// }