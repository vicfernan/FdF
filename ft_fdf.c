/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:51:03 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/26 16:14:02 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int ft_convert_hexa(char a, char b)
{
    int result;
    char *hexa;
    int i;
    int x;
    int r;

    a = ft_tolower(a);
    b = ft_tolower(b);
    hexa = "0123456789abcdef";
    x = 0;
    i = 0;
    r = 0;
    while(hexa[r++] != '\0')
    {
        if (hexa[r] == a)
            i = r;
        if (hexa[r] == b)
            x = r;
    }
    result = (i * 16) + (x * 1);
    return (result); 
}

int ft_set_color(char *str)
{
    int r;
    int g;
    int b;

    r = 0;
    g = 0;
    b = 0;
    if ((str[2] >= 0 && str[2] <= 9) || (ft_tolower(str[2]) >= 'a' && ft_tolower(str[2]) <= 'f'))
        r = ft_convert_hexa(str[2], str[3]);
    if ((str[4] >= 0 && str[4] <= 9) || (ft_tolower(str[4]) >= 'a' && ft_tolower(str[4]) <= 'f'))
        g = ft_convert_hexa(str[2], str[3]);
    if ((str[6] >= 0 && str[6] <= 9) || (ft_tolower(str[6]) >= 'a' && ft_tolower(str[6]) <= 'f'))
        b = ft_convert_hexa(str[2], str[3]);
    return (0 << 24 | r << 16 | g << 8 | b);
}

int ft_color_z(char *aux)
{
    char *cool;
    int color;
    int i;

    i = 0;
    while (aux[i] != '\0')
    {
        if (aux[i] == ',')
            break;
        i++;
    }
    cool = ft_substr(aux, i + 1, ft_strlen(aux) - i);
    color = ft_set_color(cool);
    free(cool);
    return (color);
}

void ft_map_int(char **a_map, t_vari *select)
{
	//int		**map;
    char	**aux;
    int     x;
    int     y;

    select->map = malloc(select->y_size * sizeof(int *));
    select->color_z = malloc(select->y_size * sizeof(int *));
    y = 0;
    select->max_z = 0;
    while (y <= select->y_size)
    {
        select->map[y] = malloc(select->x_size * sizeof(int));
        select->color_z[y] = malloc(select->x_size * sizeof(int));
        y++;
    }
    y = 0;
    while (y < select->y_size)
    {
        aux = ft_split(a_map[y], ' ');
        x = 0;
        while (x < select->x_size)
        {
            if (ft_strchr(aux[x], ','))
                select->color_z[y][x] = ft_color_z(aux[x]);
            else
                select->color_z[y][x] = 000;
            /*if ((aux[x][0] < '0' && aux[x][0] > 9))
            {
                printf("Wrong file!");
                exit(0);
            }*/
            select->map[y][x] = ft_atoi(aux[x]);
            if (select->map[y][x] > select->max_z)
                select->max_z = select->map[y][x];
            x++;
        }
        free(aux);
        y++;
    }
    //return (map);
}

int     ft_size_x(char **a_map)
{
    int x_size;
    int i;

    x_size = 0;
    i = 0;
    while (a_map[0][i] != '\0')
    {
        if (a_map[0][i] != ' ' && (a_map[0][i + 1] == ' ' || a_map[0][i + 1] == '\0'))
            x_size++;
        i++;
    }
    return (x_size);
}

char    **ft_read_save(char *argv, char **a_map)
{
    char    *line;
    int     fd;
    int     i;
    int     stat;

    fd = open(argv, O_RDONLY);
    stat = get_next_line(fd, &line);
    i = 0;
    while (stat >= 0)
    {
        a_map[i] = ft_strdup(line);
        free(line);
        line = NULL;
        if (stat <= 0)
            break ;
        stat = get_next_line(fd, &line);
        i++;
    }
    free(line);
    line = NULL;
    close(fd);
    if (!a_map)
        return (0);
    return (a_map);
}

int ft_size_y(char *argv)
{
    char    *line;
    int     fd;
    int     i;
    int     stat;

    fd = open(argv, O_RDONLY);
    stat = get_next_line(fd, &line);
    i = 0;
    while (stat >= 0)
    {
        free(line);
        line = NULL;
        if (stat <= 0)
            break ;
        stat = get_next_line(fd, &line);
        i++;
    }
    free(line);
    line = NULL;
    close(fd);
    return (i);
}

t_vari    ft_read_line(char *argv)
{
    char    **a_map;
    t_vari  select;

    select.y_size = ft_size_y(argv);
    a_map = ft_calloc(select.y_size + 2, sizeof(char *));
    a_map = ft_read_save(argv, a_map);
    select.x_size = ft_size_x(a_map);
    ft_map_int(a_map, &select);
    return (select);
}

