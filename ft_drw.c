/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:21:32 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/10 18:16:59 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	hooked_function(void *select)
{
    exit(0);
}

int	key_hook(int keycode, void *select)
{
    if (keycode == 53)
        exit(0);
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


void    ft_isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(1);
    *y = (*x + *y) * sin(1) - z;
}

float Remap(float value, float oldFrom, float oldTo, float newFrom, float newTo)
{
	return (value - oldFrom) / (oldTo - oldFrom) * (newTo - newFrom) + (newFrom);
}

void    ft_bresenham(float x, float y, float x1, float y1, t_vari select)
{
    float   x_step;
    float   y_step;
    int max;
    int z;
    int z1;
    float c1;
    float c2;
    float dis;
    float h;


    z = select.map[(int)y][(int)x];
    z1 = select.map[(int)y1][(int)x1];


    x *= select.space;
    y *= select.space;
    x1 *= select.space;
    y1 *= select.space;

//    printf("Z: %d\n", z);
//    printf("Z1: %d\n", z1);

    
    select.color = 0xffffff;

      
    ft_isometric(&x, &y, z);
    ft_isometric(&x1, &y1, z1);


    x += 750;
    x1 += 750;
    y1 += 250;
    y += 250;       

  /*  x += 700;
    x1 += 700;
    y1 += 80;
    y += 80;*/

    if (z != z1)
    {
        c1 = x - x1;
        c2 = y - y1;
        h = c1*c1 + c2*c2;
    }

    x_step = x1 - x;
    y_step = y1 - y;
    
//        Avance recto:
//        (x_step >= y_step)
    

    max = ft_max(ft_mod(x_step),ft_mod(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        if (z > z1)
        {
            c1 = x - x1;
            c2 = y - y1;
            dis = c1*c1 + c2*c2;
            select.color = Remap(dis, 0, h, 0xffffff, 0xff4000);
        }
        else if (z1 > z)
        {
            c1 = x - x1;
            c2 = y - y1;
            dis = c1*c1 + c2*c2;
            select.color = Remap(dis, 0, h, 0xff4000, 0xffffff); 
        }
        if (z == z1 && z == select.max_z)
            select.color = 0xff4000;
        mlx_pixel_put(select.mlx, select.win, x, y, select.color);
        x += x_step;
        y += y_step;
    }
}

/*
int     ft_set_color(t_vari select, int x, int y)
{
    if (select.map[x][y] <= select.max_z / 6)

}*/

void    ft_drw_map(t_vari select)
{
    int y;
    int x;

    y = 0;
    while(y < select.y_size)
        {
            x = 0;
            while(x < select.x_size)
            {
                if (x < select.x_size - 1)
                    ft_bresenham(x, y, x + 1, y, select);
                if (y < select.y_size - 1)
                    ft_bresenham(x, y, x, y + 1, select);
                x++;
            }
            y++;
        }
}

void    ft_init_map(t_vari select)
{
    select.mlx = mlx_init();
    select.win = mlx_new_window(select.mlx, WIN_X, WIN_Y, "-FDF Project-");
    //ft_bresenham(10, 10, 600, 600, select);
    mlx_hook(select.win, 17, 0, hooked_function, &select);
    mlx_key_hook(select.win, key_hook, &select);
    select.space = 8;
    ft_drw_map(select);
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
        ft_init_map(select);
    }
    return (0);
}

/*
int main(int argc, char **argv)
{
    t_vari  select;
    int     i;
    int     x;
    int     xo;
    int     yo;
    
    if (argc != 2)
        printf("Wrong arg!");
    if (argc == 2)
    {
        select = ft_read_line(argv[1]);
        printf(" x[%d] | y[%d]\n", select.x_size, select.y_size);
        i = 0;
        while(i < select.y_size)
        {
            x = 0;
            while(x < select.x_size)
            {
                printf("%3d", select.map[i][x]);
                x++;
            }
            printf("\n");
            i++;
        }
        xo = 560;
        yo = 540;
        select.mlx = mlx_init();
        select.win = mlx_new_window(select.mlx, WIN_X, WIN_Y, "-FDF Project-");
        mlx_hook(select.win, 17, 0, hooked_function, &select);
        mlx_key_hook(select.win, key_hook, &select);
        while (xo < 1360)
        {
            if (xo > 960)
            {
                mlx_pixel_put(select.mlx, select.win, xo, yo, 0x67a1cf);
            }
            else
                mlx_pixel_put(select.mlx, select.win, xo, yo, 0xffffff);
            xo++;
        }
        mlx_loop(select.mlx);
    }
    return (0);
}*/