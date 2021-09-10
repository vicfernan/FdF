/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:27:36 by vifernan          #+#    #+#             */
/*   Updated: 2021/04/19 14:11:28 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	const char		*s;
	size_t			i;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char) c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
