/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:51:11 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/29 16:49:48 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LIB_H
# define FDF_LIB_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# define BUFFER_SIZE 20
# define WIN_X 2560
# define WIN_Y 1440

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_case{
	int		case1;
	int		case2;
}				t_case;

typedef struct t_variables{
	t_case	key;
	t_data	img;
	float	from;
	float	to;
	int		onoff_c;
	char	*mlx;
	char	*win;
	int		**map;
	float	**color_z;
	int		scale_x;
	int		scale_y;
	int		x_size;
	float	color;
	int		max_z;
	int		y_size;
	int		space;
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	int		z;
	int		z1;
	float	max;
	int		x_start;
	int		y_start;
	float	iso;
	float	st;
	int		flag;
	char	*fn;
	int		multi_z;
	int		help;
}				t_vari;

typedef struct t_isometric{
	float	c1;
	float	c2;
	float	hipo;
	float	dis;
}				t_iso;

int		ft_slcolor2(t_vari select, t_iso isome, float x1, float y1);
float	ft_remap_x(t_vari select, float newFrom, float newTo, float x1);
int		ft_mini_printf(const char *str, ...);
t_vari	ft_read_line(char *argv);
int		ft_check_line_size(char **a_map, int y);
void	ft_start_maps(t_vari *select);
void	ft_fill_maps(int x, int y, char **aux, t_vari *select);
void	ft_map_int(char **a_map, t_vari *select);
int		ft_size_y(char *argv);
int		ft_size_x(char **a_map);
void	ft_wrog_file(void);
int		ft_convert_hexa(char a, char b);
int		ft_set_color(char *str);
int		ft_color_z(char *aux);
void	ft_clear_win(t_vari *select);
void	ft_free_map(t_vari *select);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
float	ft_remap(t_iso isome, float newFrom, float newTo);
void	ft_isometric(float *x, float *y, int z, t_vari *select);
void	ft_ajust(t_vari *select);
float	ft_isometric_mx(float x, float y, int z);
float	ft_isometric_my(float x, float y, int z);
int		ft_space_size(t_vari *select);
void	ft_help_win(t_vari *select);
void	ft_clear_win(t_vari *select);
int		get_next_line(const int fd, char **line);
void	ft_map_int(char **a_map, t_vari *select);
int		ft_size_x(char **a_map);
char	**ft_read_save(char *argv, char **a_map);
int		ft_size_y(char *argv);
int		hooked_function(t_vari *select);
int		key_hook(int keycode, t_vari *select);
void	ft_help_win(t_vari *select);
int		ft_slcolor(t_iso isome, t_vari select, float x1, float y1);
void	ft_selval(t_vari *select, float *x1, float *y1);
void	ft_bresenham(float x1, float y1, t_vari select);
void	ft_drw_map(t_vari select);

#endif
