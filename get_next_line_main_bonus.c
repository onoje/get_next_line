/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:53:32 by elduran           #+#    #+#             */
/*   Updated: 2024/12/30 15:38:46 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("onoje1.txt", O_RDONLY);
	fd2 = open("onoje2.txt", O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd1);
		if (line1)
		{
			printf("%s", line1);
			free(line1);
		}
		line2 = get_next_line(fd2);
		if (line2)
		{
			printf("%s", line2);
			free(line2);
		}
		if (!line1 && !line2)
			break ;
	}
	close(fd1);
	close(fd2);
	return (0);
}
