/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:51:03 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/20 17:01:06 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int **ft_map_int(char **a_map, t_vari *select)
{
	int		**map;
    char	**aux;
    int     x;
    int     y;

    map = malloc(select->y_size * sizeof(int *));
    y = 0;
    select->max_z = 0;
    while (y <= select->y_size)
        map[y++] = malloc(select->x_size * sizeof(int));
    y = 0;
    while (y < select->y_size)
    {
        aux = ft_split(a_map[y], ' ');
        x = 0;
        while (x < select->x_size)
        {
            map[y][x] = ft_atoi(aux[x]);
            if (map[y][x] > select->max_z)
                select->max_z = map[y][x];
            x++;
        }
        free(aux);
        y++;
    }
    return (map);
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
    select.map = ft_map_int(a_map, &select);
    return (select);
}

