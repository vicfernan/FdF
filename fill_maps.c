/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:26:56 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/02 18:03:13 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

void	ft_start_maps(t_vari *select)
{
	int	y;

	select->map = malloc(select->y_size * sizeof(int *));
	select->color_z = malloc(select->y_size * sizeof(int *));
	select->max_z = 0;
	y = 0;
	while (y < select->y_size)
	{
		select->map[y] = malloc(select->x_size * sizeof(int));
		select->color_z[y] = malloc(select->x_size * sizeof(float));
		y++;
	}
}

void	ft_fill_maps(int x, int y, char **aux, t_vari *select)
{
	if (ft_strchr(aux[x], ','))
	{
		select->onoff_c = 1;
		select->color_z[y][x] = ft_color_z(aux[x]);
	}
	else
		select->color_z[y][x] = 0xffffff;
	if (((aux[x][0] < '0' && aux[x][0] > 9) && aux[x][0] != '-') ||
			((aux[x][1] < '0' && aux[x][1] > 9) && aux[x][0] == '-') ||
			(aux[x][1] == '\0' && aux[x][0] == '-'))
		ft_wrog_file();
	select->map[y][x] = ft_atoi(aux[x]);
	if (select->map[y][x] > select->max_z)
		select->max_z = select->map[y][x];
}

void	ft_map_int(char **a_map, t_vari *select)
{
	char	**aux;
	int		x;
	int		y;
	int		len;

	ft_start_maps(select);
	y = 0;
	len = ft_check_line_size(a_map, 0);
	while (y < select->y_size)
	{
		if (len != ft_check_line_size(a_map, y))
			ft_wrog_file();
		aux = ft_split(a_map[y], ' ');
		x = 0;
		while (x < select->x_size)
		{
			ft_fill_maps(x, y, aux, select);
			free(aux[x]);
			x++;
		}
		free(aux);
		y++;
	}
}
