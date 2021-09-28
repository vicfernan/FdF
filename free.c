/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:59:40 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/28 15:21:56 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

void	ft_free_map(t_vari *select)
{
	int	y;

	y = 0;
	while (y <= select->y_size)
	{
		free(select->map[y]);
		free(select->color_z[y]);
		y++;
	}
	free(select->map);
	free(select->color_z);
}

void	ft_clear_win(t_vari *select)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			my_mlx_pixel_put(&select->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
