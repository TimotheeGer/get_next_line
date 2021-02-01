/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:42:25 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/01 10:54:17 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*ft_strnew(void)
{
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (1))))
		return (NULL);
	dest[0] = '\0';
	return (dest);
}

char				*ft_lineintemp(char *temp)
{
	char			*str;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (temp && temp[i] != '\n' && temp[i] != '\0')
	{
		i++;
	}
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (temp[j] && j < i)
	{
		str[j] = temp[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int					get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	char			*tempo;
	static char		*t[256];
	int				ret;

	ret = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (!t[fd] && (!(t[fd] = ft_strnew())))
		return (-1);
	while ((!(ft_tempavbs(t[fd]))) && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tempo = t[fd];
		t[fd] = ft_strjoin(tempo, buff);
		free(tempo);
	}
	*line = ft_lineintemp(t[fd]);
	if ((ft_newrest(t[fd])) == NULL)
	{
		free(t[fd]);
		t[fd] = NULL;
		return (0);
	}
	return (1);
}
