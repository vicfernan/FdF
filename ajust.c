/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajust.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:41:46 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/28 15:09:04 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

void	ft_ajust(t_vari *select)
{
	float	screen_x;
	float	screen_y;

	screen_x = select->x_size * select->space;
	screen_y = select->y_size * select->space;
	ft_isometric(&screen_x, &screen_y, select->max_z, select);
	select->x_start = (WIN_X - screen_x) / 2;
	select->y_start = (WIN_Y - screen_y) / 2;
}

float	ft_isometric_mx(float x, float y, int z)
{
	x = (x - y) * cos(1);
	y = (x + y) * sin(1) - z;
	return (x);
}

float	ft_isometric_my(float x, float y, int z)
{
	x = (x - y) * cos(1);
	y = (x + y) * sin(1) - z;
	return (y);
}

int	ft_space_size(t_vari *select)
{
	float	x;
	float	y;
	float	max_x;
	float	max_y;

	max_x = ft_isometric_mx(select->x_size, select->y_size,
			select->max_z) - ft_isometric_mx(0, select->y_size, select->max_z);
	max_y = ft_isometric_my(select->x_size, select->y_size,
			select->max_z) - ft_isometric_mx(select->x_size, 0, select->max_z);
	x = select->x_size;
	y = select->y_size;
	ft_isometric(&x, &y, select->max_z, select);
	if (select->x_size == select->y_size)
		x = y;
	if (max_x >= max_y)
		select->space = (ft_isometric_mx(WIN_X,
					WIN_Y, select->max_z) / max_x) * 1.2;
	else
		select->space = (ft_isometric_my(WIN_X,
					WIN_Y, select->max_z) / max_y) * 1.2;
	ft_ajust(select);
	return (select->space);
}
