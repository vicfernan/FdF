/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:16:40 by vifernan          #+#    #+#             */
/*   Updated: 2021/04/21 13:13:30 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size(int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (0);
	if (nb == -2147483648)
		nb++;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_isnegative(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

char	ft_negative(int nb, char *str)
{
	if (nb < 0)
		str[0] = '-';
	return (str[0]);
}

char	*ft_itoa(int nb)
{
	char	*str;
	size_t	i;
	size_t	flag;

	i = ft_size(nb);
	str = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (0);
	flag = 0;
	if (nb == -2147483648 && nb++)
		flag++;
	str[0] = ft_negative(nb, str);
	nb = ft_isnegative(nb);
	while (nb > 9)
	{
		if (flag == 1 && flag--)
			str[i--] = (nb % 10 + 48) + 1;
		else
			str[i--] = nb % 10 + 48;
		nb = nb / 10;
	}
	str[i] = nb + 48;
	return (str);
}
