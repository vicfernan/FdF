/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:22:03 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/02 17:40:45 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	ft_size_x(char **a_map)
{
	int	x_size;
	int	i;

	x_size = 0;
	i = 0;
	while (a_map[0][i] != '\0')
	{
		if (a_map[0][i] != ' ' &&
			(a_map[0][i + 1] == ' ' || a_map[0][i + 1] == '\0'))
			x_size++;
		i++;
	}
	return (x_size);
}

int	ft_size_y(char *argv)
{
	char	*line;
	int		fd;
	int		i;
	int		stat;

	fd = open(argv, O_RDONLY);
	line = NULL;
	stat = get_next_line(fd, &line);
	i = 1;
	while (stat >= 0)
	{
		free(line);
		line = NULL;
		if (stat <= 0)
			break ;
		stat = get_next_line(fd, &line);
		if (line[0] == '\0' || line[0] == '\n')
			i--;
		i++;
	}
	free(line);
	line = NULL;
	close(fd);
	return (i);
}
