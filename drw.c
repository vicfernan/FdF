/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:21:32 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/29 16:51:10 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	ft_slcolor(t_iso isome, t_vari select, float x1, float y1);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_drw_map(t_vari select)
{
	select.y = 0;
	while (select.y < select.y_size)
	{
		select.x = 0;
		while (select.x < select.x_size)
		{
			if (select.x < select.x_size - 1)
				ft_bresenham(select.x + 1, select.y, select);
			if (select.y < select.y_size - 1)
				ft_bresenham(select.x, select.y + 1, select);
			select.x++;
		}
		select.y++;
	}
	mlx_put_image_to_window(select.mlx, select.win, select.img.img, 0, 0);
	mlx_string_put(select.mlx, select.win, 2000, 50,
		0xffffff, select.fn);
	mlx_string_put(select.mlx, select.win, 2000, 80,
		0xffffff, "Click on <space> for help");
}

void	ft_init_map(t_vari select)
{
	select.iso = 1;
	select.mlx = mlx_init();
	select.win = mlx_new_window(select.mlx, WIN_X, WIN_Y, "-FDF Project-");
	mlx_hook(select.win, 17, 0, hooked_function, &select);
	mlx_key_hook(select.win, key_hook, &select);
	select.space = ft_space_size(&select);
	select.img.img = mlx_new_image(select.mlx, WIN_X, WIN_Y);
	select.img.addr = mlx_get_data_addr(select.img.img,
			&select.img.bits_per_pixel, &select.img.line_length,
			&select.img.endian);
	ft_drw_map(select);
	mlx_loop(select.mlx);
	ft_free_map(&select);
}

int	main(int argc, char **argv)
{
	t_vari	select;

	if (argc != 2)
		ft_mini_printf("Wrong arg!\n");
	if (argc == 2)
	{
		select = ft_read_line(argv[1]);
		select.fn = argv[1];
		select.multi_z = 1;
		select.help = 0;
		select.key.case1 = 0;
		select.key.case2 = 0;
		ft_init_map(select);
	}
	return (0);
}
