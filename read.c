/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:51:03 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/01 19:02:55 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

//void	leaks(void);

/*void	leaks(void)
{
	system("leaks fdf");
}
*/

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
    x = -1;
    i = -1;
    r = -1;
    while(hexa[++r] != '\0')
    {
        if (hexa[r] == a)
            i = r;
        if (hexa[r] == b)
            x = r;
    }
    if ((x < 0) || (i < 0))
    {
        printf("Wrong ?file!\n");
        exit(0);
    }
    result = (i * 16) + (x * 1);
    return (result); 
}

int ft_set_color(char *str)
{
    int r;
    int g;
    int b;

    if (str[0] != '0' || str[1] != 'x')
    {
        printf("Wrong *file!\n");
        exit(0);
    }
    r = ft_convert_hexa(str[2], str[3]);
    if (ft_strlen(str) == 4)
    {
        g = ft_convert_hexa('0', '0');
        b = ft_convert_hexa('0', '0');
    }
    else if (ft_strlen(str) == 6)
    {
        g = ft_convert_hexa(str[4], str[5]);
        b = ft_convert_hexa('0', '0');
    }
    else
    {
        g = ft_convert_hexa(str[4], str[5]);
        b = ft_convert_hexa(str[6], str[7]);
    }
    return (r << 16 | g << 8 | b);
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
    char	**aux;
    int     x;
    int     y;

    select->map = malloc(select->y_size * sizeof(int *));
    select->color_z = malloc(select->y_size * sizeof(int *));
    select->max_z = 0;
    y = 0;
    //printf("%d\n", select->y_size);
    while (y < select->y_size)
    {
        select->map[y] = malloc(select->x_size * sizeof(int));
        select->color_z[y] = malloc(select->x_size * sizeof(float));
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
            {
                select->onoff_c = 1;
                select->color_z[y][x] = ft_color_z(aux[x]);
            }
            else
                select->color_z[y][x] = 0xffffff;
            if (((aux[x][0] < '0' && aux[x][0] > 9) && aux[x][0] != '-') || 
                    ((aux[x][1] < '0' && aux[x][1] > 9) && aux[x][0] == '-') ||
                    (aux[x][1] == '\0' && aux[x][0] == '-'))
            {
                printf("Wrong file!\n");
                exit(0);
            }
            select->map[y][x] = ft_atoi(aux[x]);
            if (select->map[y][x] > select->max_z)
                select->max_z = select->map[y][x];
            free(aux[x]);
            x++;
        }
        free(aux);
        y++;
    }
    //system("leaks fdf");
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
    line = NULL;
    stat = get_next_line(fd, &line);
    i = 0;
    while (stat >= 0)
    {
        a_map[i] = ft_strdup(line);
        //printf("[%d]%s ** |\n\n\n\n\n\n\n\n\n\n", i, a_map[i]);
        free(line);
        line = NULL;
        if (stat <= 0)
            break ;
        stat = get_next_line(fd, &line);
        if (line[0] == '\0' || line[0] == '\n')
            break ;
        i++;
    }
    free(line);
    line = NULL;
    close(fd);
    if (a_map[0][0] == '\0' || a_map[0][0] == '\n')
    {
        printf("Wrong **file!\n");
        exit(0);
    }
    return (a_map);
}

int ft_size_y(char *argv)
{
    char    *line;
    int     fd;
    int     i;
    int     stat;

    fd = open(argv, O_RDONLY);
    line = NULL;
    stat = get_next_line(fd, &line);
    i = 1;
    while (stat >= 0)
    {
        free(line);
        line = NULL;
        if (stat <= 0)
            break ;
        stat = get_next_line(fd, &line);
        if (line[0] == '\0' || line[0] == '\n')
            i--;
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
    int y;

    select.y_size = ft_size_y(argv);
    select.onoff_c = 0;
    a_map = ft_calloc(select.y_size + 1, sizeof(char *));
    a_map = ft_read_save(argv, a_map);
    select.x_size = ft_size_x(a_map);
    ft_map_int(a_map, &select);
    y = 0;
    while (y <= select.y_size)
    {
        free(a_map[y]);
        y++;
    }
    free(a_map);
    return (select);
}

