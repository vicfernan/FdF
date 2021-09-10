/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:35:43 by vifernan          #+#    #+#             */
/*   Updated: 2021/04/21 13:26:39 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start(const char *s, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		flag = 0;
		while (set[j] != '\0')
		{
			if (s[i] == set[j])
				flag++;
			j++;
		}
		if (flag == 0)
			break ;
		i++;
	}
	return (i);
}

size_t	ft_end(const char *s, const char *set, size_t start)
{
	size_t	size_s;
	size_t	j;
	size_t	flag;

	size_s = ft_strlen(s) - 1;
	while (size_s > start)
	{
		j = 0;
		flag = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s[size_s])
				flag++;
			j++;
		}
		if (flag == 0)
			break ;
		size_s--;
	}
	return (size_s);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	size;
	size_t	start;
	size_t	end;
	size_t	j;
	char	*str;

	if (s && set)
	{
		start = ft_start(s, set);
		end = ft_end(s, set, start);
		size = end - start + 1;
		str = (char *)malloc(size + 1);
		if (!str)
			return (0);
		j = 0;
		while (size--)
			str[j++] = s[start++];
		str[j] = '\0';
		return (str);
	}
	return (0);
}
