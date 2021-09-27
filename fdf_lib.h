/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:51:11 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/27 15:11:04 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LIB_H
# define FDF_LIB_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
#define BUFFER_SIZE 20
#define WIN_X 1920
#define WIN_Y 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct t_variables{
    t_data img;
    char *mlx;
    char *win;
	int **map;
    float **color_z;
    int scale_x;
    int scale_y;
    int x_size;
    int color;
    int max_z;
    int y_size;
    int space;
    float x;
    float y;
    float x_step;
    float y_step;
    int z;
    int z1;
    float max;
    int x_start;
    int y_start;
    float iso;
    float st;
    int flag;
    char *fn;
    int multi_z;
    int help;
}	t_vari;

typedef struct t_isometric{
    float c1;
    float c2;
    float hipo;
    float dis;
}	t_iso;

int		get_next_line(const int fd, char **line);
void ft_map_int(char **a_map, t_vari *select);
int     ft_size_x(char **a_map);
char    **ft_read_save(char *argv, char **a_map);
int ft_size_y(char *argv);
t_vari    ft_read_line(char *argv);
int	hooked_function(t_vari *select);
int	key_hook(int keycode, t_vari *select);
void    ft_drw_map(t_vari select);

#endif