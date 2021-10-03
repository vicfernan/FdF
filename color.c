/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:55:52 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/03 16:01:18 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

float	ft_remap(t_iso isome, float newFrom, float newTo)
{
	return ((isome.dis - 0) / (isome.hipo - 0) * (newTo - newFrom) + (newFrom));
}

float	ft_remap_x(t_vari select, float newFrom, float newTo, float x1)
{
	return ((x1 - select.x) / (select.space - 0) * (
			newTo - newFrom) + (newFrom));
}

int	ft_slcolor2(t_vari select, t_iso isome, float x1, float y1)
{
	if (select.z > select.z1)
	{
		isome.c1 = select.x - x1;
		isome.c2 = select.y - y1;
		isome.dis = isome.c1 * isome.c1 + isome.c2 * isome.c2;
		select.color = ft_remap(isome, 0xffffff, select.from);
	}
	else if (select.z1 > select.z)
	{
		isome.c1 = select.x - x1;
		isome.c2 = select.y - y1;
		isome.dis = isome.c1 * isome.c1 + isome.c2 * isome.c2;
		select.color = ft_remap(isome, select.from, 0xffffff);
	}
	else
		select.color = 0xffffff;
	return (select.color);
}

int	ft_slcolor(t_iso isome, t_vari select, float x1, float y1)
{
	if (select.z > select.z1)
	{
		isome.c1 = select.x - x1;
		isome.c2 = select.y - y1;
		isome.dis = isome.c1 * isome.c1 + isome.c2 * isome.c2;
		select.color = ft_remap(isome, 0xffffff, 0xff4000);
	}
	else if (select.z1 > select.z)
	{
		isome.c1 = select.x - x1;
		isome.c2 = select.y - y1;
		isome.dis = isome.c1 * isome.c1 + isome.c2 * isome.c2;
		select.color = ft_remap(isome, 0xff4000, 0xffffff);
	}
	else if (select.z > 0 || select.z1 > 0)
		select.color = 0xff4000;
	else
		select.color = 0xffffff;
	return (select.color);
}
