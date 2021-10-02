/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:55:52 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/02 19:32:48 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

float	ft_remap(t_iso isome, float newFrom, float newTo)
{
	return ((isome.dis - 0) / (isome.hipo - 0) * (newTo - newFrom) + (newFrom));
}

float	ft_remap2(t_vari select, float newFrom, float newTo, float step)
{
	select.z = 0;
	return ((step - 0) / (step - 0) * (newTo - newFrom) + (newFrom));
}

int	ft_slcolor2(t_vari select, float x1, float y1)
{
	float step;

	if ((int)x1 && (select.from != 0xffffff || select.to != 0xffffff))
	{
		printf("entra");
		step = select.x - x1;
		select.color = ft_remap2(select, select.from, select.to, step);
	}
	else if (((int)y1 && (select.from != 0xffffff || select.to != 0xffffff)))
	{
		step = select.y - y1;
		select.color = ft_remap2(select, select.to, select.from, step);
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
