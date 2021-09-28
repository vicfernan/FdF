/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:55:52 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/28 15:52:54 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

float	ft_remap(t_iso isome, float newFrom, float newTo)
{
	return ((isome.dis - 0) / (isome.hipo - 0) * (newTo - newFrom) + (newFrom));
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
