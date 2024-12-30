/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:53:37 by elduran           #+#    #+#             */
/*   Updated: 2024/12/30 13:55:45 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		check_new_line_character(char *str);
void	initialize_str(char **str);
char	*ft_strjoin(char *str, char *line);
char	*read_before_new_line(char *str);
char	*read_after_new_line(char *str);
char	*read_file(char *str, int fd);
char	*get_next_line(int fd);

#endif