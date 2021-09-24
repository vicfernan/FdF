/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:21:32 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/24 19:17:01 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"


void    ft_isometric(float *x, float *y, int z, t_vari *select)
{
    *x = (*x - *y) * cos(select->iso);
    *y = (*x + *y) * sin(select->iso) - z;
}

void ft_ajust(t_vari *select)
{
    float screen_x;
    float screen_y;

    screen_x = select->x_size * select->space;
    screen_y = select->y_size * select->space;  
    ft_isometric(&screen_x, &screen_y, select->max_z, select);
    select->x_start = (WIN_X - screen_x) / 2;
    select->y_start = (WIN_Y - screen_y) / 2;
}

int	hooked_function(void *select)
{
    exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_clear_win(t_vari *select)
{
    int x;
    int y;

    y = 0;
    while(y < WIN_Y)
    {
        x = 0;
        while(x < WIN_X)
        {
            my_mlx_pixel_put(&select->img, x, y, 0x000000);
            x++;
        }
        y++;
    }
}

int	key_hook(int keycode, t_vari *select)
{
    if (keycode == 53)
        exit(0);
    if (keycode == 125)
    {
        if (select->iso > 0)
        {
            select->iso -= 0.1;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_ajust(select);
            ft_drw_map(*select);
        }
    }

    if (keycode == 6)
    {
            select->multi_z += 1;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_ajust(select);
            ft_drw_map(*select);
    }

    if (keycode == 7)
    {
            select->multi_z -= 1;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_ajust(select);
            ft_drw_map(*select);
    }


    if (keycode == 126)
    {
        if (select->iso < 1)
        {
            select->iso += 0.1;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_ajust(select);
            ft_drw_map(*select);
        }
    }
    if (keycode == 69)
    {
        select->space += 1;
        mlx_clear_window(select->mlx, select->win);
        ft_clear_win(select);
        ft_ajust(select);
        ft_drw_map(*select);
    }
    if (keycode == 78)
    {
        if (select->space > 0)
        {
            select->space -= 1;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_ajust(select);
            ft_drw_map(*select);
        }
    }
    if (keycode == 2)
    {
        if (select->space > 0)
        {

            select->x_start += 10;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_drw_map(*select);
        }
    }
    if (keycode == 0)
    {
        if (select->space > 0)
        {
            select->x_start -= 10;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_drw_map(*select);
        }
    }
    if (keycode == 1)
    {
        if (select->space > 0)
        {
            select->y_start += 10;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_drw_map(*select);
        }
    }
    if (keycode == 13)
    {
        if (select->space > 0)
        {
            select->y_start -= 10;
            mlx_clear_window(select->mlx, select->win);
            ft_clear_win(select);
            ft_drw_map(*select);
        }
    }
    mlx_string_put( select->mlx, select->win, 1600, 50, 0xffffff, select->fn);
    return (0);
}

float   ft_max(float x, float y)
{
    if (x > y)
        return (x);
    return (y);
}

float   ft_mod(float x)
{
    if (x < 0)
        return (x * -1);
    return (x);
}

float Remap(t_iso isome, float newFrom, float newTo)
{
	return (isome.dis - 0) / (isome.hipo - 0) * (newTo - newFrom) + (newFrom);
}

int ft_slcolor(t_iso isome, t_vari select, float x1, float y1)
{
    if (select.z > select.z1)
    {
        //printf("%f\n", select.color_z[select.y][select.x]);
        isome.c1 = select.x - x1;
        isome.c2 = select.y - y1;
        isome.dis = isome.c1*isome.c1 + isome.c2*isome.c2;
        select.color = Remap(isome, 0xffffff, 0xff4000);
    }
    else if (select.z1 > select.z)
    {
        isome.c1 = select.x - x1;
        isome.c2 = select.y - y1;
        isome.dis = isome.c1*isome.c1 + isome.c2*isome.c2;
        select.color = Remap(isome, 0xff4000, 0xffffff); 
    }
    /*
    else if (select.z == select.z1 && select.z == select.max_z)
        select.color = 0xff4000;*/
    else if (select.z > 0 || select.z1 > 0)
        select.color = 0xff4000;
    else
        select.color = 0xffffff;
    return (select.color);
}

void ft_selval(t_vari *select, float *x1, float *y1)
{
    select->z = select->map[(int)select->y][(int)select->x];
    select->z1 = select->map[(int)*y1][(int)*x1];
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
}


void    ft_bresenham(float x1, float y1, t_vari select)
{
    t_iso isome;

    ft_selval(&select, &x1, &y1);
    select.x_step = x1 - select.x;
    select.y_step = y1 - select.y;
    select.max = ft_max(ft_mod(select.x_step),ft_mod(select.y_step));
    select.x_step /= select.max;
    select.y_step /= select.max;

    if (select.z != select.z1)
    {
        isome.c1 = select.x - x1;
        isome.c2 = select.y - y1;
        isome.hipo = isome.c1*isome.c1 + isome.c2*isome.c2;
    }
    while ((int)(select.x - x1) || (int)(select.y - y1))
    {
        select.color = ft_slcolor(isome, select, x1, y1);
        if ((select.x > 0 && select.x < WIN_X) && (select.y > 0 && select.y < WIN_Y))
            my_mlx_pixel_put(&select.img, select.x, select.y, select.color);
        select.x += select.x_step;
        select.y += select.y_step;
    }
}

float    ft_isometric_mx(float x, float y, int z)
{
    x = (x - y) * cos(1);
    y = (x + y) * sin(1) - z;
    return (x);
}

float    ft_isometric_my(float x, float y, int z)
{
    x = (x - y) * cos(1);
    y = (x + y) * sin(1) - z;
    return (y);
}

int ft_space_size(t_vari *select)
{
    float x;
    float y;
    float max_x;
    float max_y;

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
        select->space = (ft_isometric_mx(WIN_X, WIN_Y, select->max_z) / max_x) * 1.2;
    else
        select->space = (ft_isometric_my(WIN_X, WIN_Y, select->max_z) / max_y) * 1.2;
    ft_ajust(select);
    return(select->space);
}

void    ft_drw_map(t_vari select)
{
    select.y = 0;
    while(select.y < select.y_size)
    {
        select.x = 0;
        while(select.x < select.x_size)
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
}

void    ft_init_map(t_vari select)
{
    select.iso = 1;
    select.mlx = mlx_init();
    select.win = mlx_new_window(select.mlx, WIN_X, WIN_Y, "-FDF Project-");
    mlx_hook(select.win, 17, 0, hooked_function, &select);
    mlx_key_hook(select.win, key_hook, &select);
    select.space = ft_space_size(&select);
    select.img.img = mlx_new_image(select.mlx, WIN_X, WIN_Y);
    select.img.addr = mlx_get_data_addr(select.img.img, &select.img.bits_per_pixel, &select.img.line_length, &select.img.endian);
    ft_drw_map(select);
    mlx_string_put( select.mlx, select.win, 1600, 50, 0xffffff, select.fn);
    mlx_loop(select.mlx);
}

int main(int argc, char **argv)
{
    t_vari  select;
    
    if (argc != 2)
        printf("Wrong arg!");
    if (argc == 2)
    {
        select = ft_read_line(argv[1]);
        select.fn = argv[1];
        select.multi_z = 1;
        ft_init_map(select);
    }
    return (0);
}