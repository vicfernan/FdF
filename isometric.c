/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:08:49 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/03 15:54:59 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

void	ft_isometric(float *x, float *y, int z, t_vari *select)
{
	*x = (*x - *y) * cos(select->iso);
	*y = (*x + *y) * sin(select->iso) - z;
}

float	ft_max(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

float	ft_mod(float x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void	ft_selval(t_vari *select, float *x1, float *y1)
{
	select->z = select->map[(int)select->y][(int)select->x];
	select->z1 = select->map[(int)*y1][(int)*x1];
	select->from = select->color_z[(int)select->y][(int)select->x];
	select->to = select->color_z[(int)*y1][(int)*x1];
	select->z *= select->multi_z;
	select->z1 *= select->multi_z;
	select->x *= select->space;
	select->y *= select->space;
	*x1 *= select->space;
	*y1 *= select->space;
	ft_isometric(&select->x, &select->y, select->z, select);
	ft_isometric(x1, y1, select->z1, select);
	select->x += select->x_start;
	select->y += select->y_start;
	*x1 += select->x_start;
	*y1 += select->y_start;
	select->x_step = *x1 - select->x;
	select->y_step = *y1 - select->y;
	select->max = ft_max(ft_mod(select->x_step), ft_mod(select->y_step));
}

void	ft_bresenham(float x1, float y1, t_vari select)
{
	t_iso	isome;

	ft_selval(&select, &x1, &y1);
	select.x_step /= select.max;
	select.y_step /= select.max;
	if (select.z != select.z1)
	{
		isome.c1 = select.x - x1;
		isome.c2 = select.y - y1;
		isome.hipo = isome.c1 * isome.c1 + isome.c2 * isome.c2;
	}
	while ((int)(select.x - x1) || (int)(select.y - y1))
	{
		if (select.onoff_c == 0)
			select.color = ft_slcolor(isome, select, x1, y1);
		else if (select.onoff_c == 1 && (select.z != select.z1))
			select.color = ft_slcolor2(select, isome, x1, y1);
		else
			select.color = select.from;
		if ((select.x > 0 && select.x < WIN_X)
			&& (select.y > 0 && select.y < WIN_Y))
			my_mlx_pixel_put(&select.img, select.x, select.y, select.color);
		select.x += select.x_step;
		select.y += select.y_step;
	}
}
