/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:15:35 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/29 16:52:18 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	hooked_function(t_vari *select)
{
	select->help = 0;
	exit(0);
}

void	ft_select_case(int keycode, t_vari *select)
{
	if (select->key.case2 == 1)
		ft_drw_map(*select);
	else if (select->key.case1 == 1)
	{
		ft_ajust(select);
		ft_drw_map(*select);
	}
	else if (keycode == 49)
	{
		if (select->help == 0)
		{
			select->help++;
			ft_help_win(select);
		}
		else
		{
			select->help = 0;
			ft_drw_map(*select);
		}
	}
	select->key.case1 = 0;
	select->key.case2 = 0;
}

void	ft_case_1(int keycode, t_vari *select)
{
	if (keycode == 6 && select->help == 0)
	{
		select->key.case1++;
		select->multi_z += 1;
	}
	if (keycode == 7)
	{
		select->multi_z -= 1;
		select->key.case1++;
	}
	if (keycode == 126 && select->help == 0 && select->iso < 1.2)
	{
		select->key.case1++;
		select->iso += 0.1;
	}
	if (keycode == 69 && select->help == 0)
	{
		select->key.case1++;
		select->space += 1;
	}
	if (keycode == 78 && select->help == 0 && select->space > 0)
	{
		select->key.case1++;
		select->space -= 1;
	}
}

void	ft_case_2(int keycode, t_vari *select)
{
	if (keycode == 2 && select->help == 0 && select->space > 0)
	{
		select->key.case2++;
		select->x_start += 10;
	}
	if (keycode == 0 && select->help == 0 && select->space > 0)
	{
		select->key.case2++;
		select->x_start -= 10;
	}
	if (keycode == 1 && select->help == 0 && select->space > 0)
	{
		select->key.case2++;
		select->y_start += 10;
	}
	if (keycode == 13 && select->help == 0 && select->space > 0)
	{
		select->key.case2++;
		select->y_start -= 10;
	}
}

int	key_hook(int keycode, t_vari *select)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 125 && select->help == 0 && select->iso > 0)
	{
		select->key.case1++;
		select->iso -= 0.1;
	}
	if (keycode == 8 && select->help == 0 && ++select->key.case2)
	{
		if (select->onoff_c == 1)
			select->onoff_c = 0;
		else
			select->onoff_c = 1;
	}
	ft_case_1(keycode, select);
	ft_case_2(keycode, select);
	if (select->key.case1 > 0 || select->key.case2 > 0 || keycode == 49)
	{
		mlx_clear_window(select->mlx, select->win);
		ft_clear_win(select);
		ft_select_case(keycode, select);
		mlx_string_put(select->mlx, select->win, 2000,
			50, 0xffffff, select->fn);
	}
	return (keycode);
}
