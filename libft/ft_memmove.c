/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:45:35 by vifernan          #+#    #+#             */
/*   Updated: 2021/04/13 12:16:03 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	s = src;
	d = dst;
	i = 0;
	if (d == 0 && s == 0)
		return (0);
	if (s > d)
		ft_memcpy(d, s, len);
	else
		while (len--)
			*((unsigned char *) dst + len) = *((unsigned char *) src + len);
	return (dst);
}
