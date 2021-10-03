/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:51:03 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/03 16:10:25 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

void	ft_wrog_file(void)
{
	ft_mini_printf("Wrong file!\n");
	exit(0);
}

char	*ft_free_line(char *line)
{
	free(line);
	line = NULL;
	return (line);
}

int	ft_check_line_size(char **a_map, int y)
{
	char	**aux;
	int		x;

	aux = ft_split(a_map[y], ' ');
	x = 0;
	while (aux[x])
		x++;
	return (x);
}

char	**ft_read_save(char *argv, char **a_map)
{
	char	*line;
	int		fd;
	int		i;
	int		stat;

	fd = open(argv, O_RDONLY);
	if (fd != 3)
		ft_wrog_file();
	stat = get_next_line(fd, &line);
	i = 0;
	while (stat >= 0)
	{
		a_map[i++] = ft_strdup(line);
		line = ft_free_line(line);
		if (stat <= 0)
			break ;
		stat = get_next_line(fd, &line);
		if (line[0] == '\0' || line[0] == '\n')
			break ;
	}
	line = ft_free_line(line);
	close(fd);
	if (a_map[0][0] == '\0' || a_map[0][0] == '\n')
		ft_wrog_file();
	return (a_map);
}

t_vari	ft_read_line(char *argv)
{
	char	**a_map;
	t_vari	select;
	int		y;

	select.y_size = ft_size_y(argv);
	select.onoff_c = 0;
	a_map = ft_calloc(select.y_size + 1, sizeof(char *));
	a_map = ft_read_save(argv, a_map);
	select.x_size = ft_size_x(a_map);
	ft_map_int(a_map, &select);
	y = 0;
	while (y <= select.y_size)
	{
		free(a_map[y]);
		y++;
	}
	free(a_map);
	return (select);
}
