/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:17:29 by vifernan          #+#    #+#             */
/*   Updated: 2021/09/24 18:27:34 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

char	*freestatic(char **s)
{
	free(*s);
	*s = NULL;
	return (*s);
}

int	ft_finalline(char **s, char **line)
{
	char	*aux;
	int		i;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\0')
	{
		*line = ft_strdup(*s);
		*s = freestatic(&(*s));
	}
	else if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		aux = ft_strdup(&(*s)[i + 1]);
		free(*s);
		*s = aux;
		if ((*s)[0] == 0)
			*s = freestatic(&(*s));
		return (1);
	}
	return (0);
}

int	ft_status(int resread, char	**s, char **line)
{
	if (resread < 0)
	{
		*s = freestatic(&(*s));
		return (-1);
	}
	else if (!(*s) && resread == 0)
		return (0);
	else
		return (ft_finalline(&(*s), line));
}

char	*ft_sfd_cutlines(char **s, char *buffer)
{
	char	*aux;

	if (!(*s))
		*s = ft_strdup(buffer);
	else
	{
		aux = ft_strjoin(*s, buffer);
		free(*s);
		*s = aux;
	}
	return (*s);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			resread;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	resread = 1;
	while (resread > 0)
	{
		resread = read(fd, buffer, BUFFER_SIZE);
		if (resread < 0)
			return (-1);
		buffer[resread] = '\0';
		s[fd] = ft_sfd_cutlines(&s[fd], buffer);
		if (ft_strchr(s[fd], '\n') != 0)
			break ;
	}
	return (ft_status(resread, &s[fd], line));
}
