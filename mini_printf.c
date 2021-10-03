/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:27:57 by vifernan          #+#    #+#             */
/*   Updated: 2021/10/03 15:57:02 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	ft_str_put(char *aux)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (aux[i] != '\0')
	{
		x += write(1, &aux[i], 1);
		i++;
	}
	return (x);
}

int	ft_number(unsigned int n)
{
	int	x;

	x = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		x++;
	}
	if (n > 9)
		x += ft_number(n / 10);
	if (n || (n == 0 && x == 0))
		x++;
	ft_putchar_fd((n % 10) + 48, 1);
	return (x);
}

int	ft_count(va_list arg, const char *str)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			x += ft_str_put(va_arg(arg, char *));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			x += ft_number((unsigned int)va_arg(arg, int));
			i++;
		}
		else
			x += write(1, &str[i], 1);
		i++;
	}
	return (x);
}

int	ft_mini_printf(const char *str, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, str);
	count += ft_count(arg, str);
	va_end(arg);
	return (count);
}
