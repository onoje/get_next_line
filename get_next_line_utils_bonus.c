/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:53:42 by elduran           #+#    #+#             */
/*   Updated: 2024/12/30 13:57:52 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	x;

	if (!str)
		return (0);
	x = 0;
	while (str[x])
		x++;
	return (x);
}

int	check_new_line_character(char *str)
{
	int	x;

	if (!str)
		return (0);
	x = 0;
	while (str[x])
	{
		if (str[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

void	initialize_str(char **str)
{
	if (*str == NULL)
	{
		*str = malloc(1);
		(*str)[0] = '\0';
	}
}

char	*ft_strjoin(char *str, char *line)
{
	int		x;
	int		y;
	char	*merged_str;

	merged_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(line) + 1));
	if (!merged_str)
	{
		free (str);
		return (NULL);
	}
	x = 0;
	while (str[x])
	{
		merged_str[x] = str[x];
		x++;
	}
	y = 0;
	while (line[y])
		merged_str[x++] = line[y++];
	merged_str[x] = '\0';
	free (str);
	return (merged_str);
}
