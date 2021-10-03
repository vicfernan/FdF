/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:17:01 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/03 15:59:58 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	ft_convert_hexa(char a, char b)
{
	int		result;
	char	*hexa;
	int		i;
	int		x;
	int		r;

	a = ft_tolower(a);
	b = ft_tolower(b);
	hexa = "0123456789abcdef";
	x = -1;
	i = -1;
	r = -1;
	while (hexa[++r] != '\0')
	{
		if (hexa[r] == a)
			i = r;
		if (hexa[r] == b)
			x = r;
	}
	if ((x < 0) || (i < 0))
		ft_wrog_file();
	result = (i * 16) + (x * 1);
	return (result);
}

int	ft_set_color(char *str)
{
	int	r;
	int	g;
	int	b;

	if ((str[0] != '0' || str[1] != 'x') || (
			(str[0] == '0' && str[1] == 'x') && (str[2] == '\0')))
		ft_wrog_file();
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

int	ft_color_z(char *aux)
{
	char	*cool;
	int		color;
	int		i;

	i = 0;
	while (aux[i] != '\0')
	{
		if (aux[i] == ',')
			break ;
		i++;
	}
	cool = ft_substr(aux, i + 1, ft_strlen(aux) - i);
	color = ft_set_color(cool);
	free(cool);
	return (color);
}
