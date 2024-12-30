/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:53:39 by elduran           #+#    #+#             */
/*   Updated: 2024/12/30 14:01:44 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_before_new_line(char *str)
{
	int		x;
	char	*before_new_line;

	x = 0;
	if (str[x] == '\0')
		return (NULL);
	while (str[x] != '\n' && str[x])
		x++;
	before_new_line = malloc(sizeof(char) * (x + 2));
	if (!before_new_line)
		return (NULL);
	x = 0;
	while (str[x] != '\n' && str[x])
	{
		before_new_line[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
		before_new_line[x++] = '\n';
	before_new_line[x] = '\0';
	return (before_new_line);
}

char	*read_after_new_line(char *str)
{
	int		x;
	int		y;
	char	*after_new_line;

	x = 0;
	while (str[x] != '\n' && str[x])
		x++;
	if (!str[x])
	{
		free (str);
		return (NULL);
	}
	after_new_line = malloc(sizeof(char) * (ft_strlen(str) - x + 1));
	if (!after_new_line)
		return (NULL);
	x++;
	y = 0;
	while (str[x])
		after_new_line[y++] = str[x++];
	after_new_line[y] = '\0';
	free (str);
	return (after_new_line);
}

char	*read_file(char *str, int fd)
{
	char	*line;
	int		bytes_read;

	initialize_str(&str);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			free(str);
			return (NULL);
		}
		line[bytes_read] = '\0';
		str = ft_strjoin(str, line);
		if (check_new_line_character(str) == 1)
			break ;
	}
	free (line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*readed_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buffer[fd] = read_file(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	readed_line = read_before_new_line(buffer[fd]);
	buffer[fd] = read_after_new_line (buffer[fd]);
	return (readed_line);
}