/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:57:14 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/02 17:52:35 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

void	ft_str_puthelp1(t_vari *select)
{
	mlx_put_image_to_window(select->mlx, select->win, select->img.img, 0, 0);
	mlx_string_put(select->mlx, select->win, 500, 300, 0xffffff, "HELP\\.");
	mlx_string_put(select->mlx, select->win, 780, 390,
		0xffffff, "Click on <esc> to exit");
	mlx_string_put(select->mlx, select->win, 780, 420,
		0xffffff, "Click on <+> to zoom in");
	mlx_string_put(select->mlx, select->win, 780, 450,
		0xffffff, "Click on <-> to zoom out");
	mlx_string_put(select->mlx, select->win, 780, 480,
		0xffffff, "Click on <a> to move left");
	mlx_string_put(select->mlx, select->win, 780, 510,
		0xffffff, "Click on <d> to move right");
	mlx_string_put(select->mlx, select->win, 780, 540,
		0xffffff, "Click on <s> to move down");
}

void	ft_str_puthelp2(t_vari *select)
{
	mlx_string_put(select->mlx, select->win, 780, 570,
		0xffffff, "Click on <w> to move up");
	mlx_string_put(select->mlx, select->win, 780, 600,
		0xffffff, "Click on <z> to increase z value");
	mlx_string_put(select->mlx, select->win, 780, 630,
		0xffffff, "Click on <x> to decrease z value");
	mlx_string_put(select->mlx, select->win, 780, 660,
		0xffffff, "Click on <up> to change perspective");
	mlx_string_put(select->mlx, select->win, 780, 690,
		0xffffff, "Click on <down> to change perspective");
	mlx_string_put(select->mlx, select->win, 1200, 900,
		0xffffff, "Click on <space> to exit help");
}

void	ft_help_win(t_vari *select)
{	
	int	x;
	int	y;

	y = 200;
	while (y < 880)
	{
		x = 400;
		while (x < 1520)
		{
			my_mlx_pixel_put(&select->img, x, y, 0x0000ff);
			x++;
		}
		y++;
	}
	ft_str_puthelp1(select);
	ft_str_puthelp2(select);
}
