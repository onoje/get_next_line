/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:24:59 by elduran           #+#    #+#             */
/*   Updated: 2024/12/30 15:37:26 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd = open("elif.txt", O_RDONLY);
	int		x = 0;
	char	*line;

	while (x < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		++x;
	}
	close(fd);
	return (0);
}

int	main(void)
{
	int		fd = open("onoje.txt", O_RDONLY);
	int		i = 0;
	char	*line1;
	char	*arr[100];

	while (line1 = get_next_line(fd))
	{
		arr[i] = line1;
		i++;
	}
	while (arr[--i])
		printf("%s", arr[i]);
	close(fd);
	return (0);
}
