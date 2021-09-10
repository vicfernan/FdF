/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:30:23 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/08 17:50:00 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_returni(char c, const char *s, size_t i)
{
	size_t	size;

	size = 0;
	while (i < ft_strlen(s) && s[i] != c)
	{
		size++;
		i++;
	}
	i = i - size;
	while (size--)
		i++;
	return (i);
}

char	*ft_str(char c, const char *s, size_t i)
{
	size_t	j;
	char	*str;
	size_t	size;

	size = 0;
	while (i < ft_strlen(s) && s[i] != c)
	{
		size++;
		i++;
	}
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	i = i - size;
	j = 0;
	while (size--)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

size_t	ft_tabsize(char const *s, char c)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			z++;
		}
		i++;
	}
	return (z);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**tab;
	size_t	t;

	if (!s)
		return (0);
	tab = ft_calloc((ft_tabsize(s, c) + 1), sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	t = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		size = 0;
		if (t < ft_tabsize(s, c))
		{
			tab[t++] = ft_str(c, s, i);
			i = ft_returni(c, s, i);
		}
	}
	return (tab);
}
