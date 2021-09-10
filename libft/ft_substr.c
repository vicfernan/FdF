/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:27:13 by vifernan          #+#    #+#             */
/*   Updated: 2021/04/20 11:54:52 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_exactsize(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			j++;
		i++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	str = malloc(sizeof(char) * (ft_exactsize(s, start, len) + 1));
	if (!str)
		return (0);
	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		if (j >= start && i < len)
			str[i++] = s[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}
