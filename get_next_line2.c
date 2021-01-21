/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:21:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/01/21 16:02:40 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[j] != '\0')
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		if (s2[j] == '\n')
		{
			str[i] = '\0';
			return (str);
		}
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char		*newbuff(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			return (&buff[i + 1]);
		}
		i++;
	}
	return (buff);
}

char		*get_first_line(int fd, char *buff)
{
	int ret;
	char *str;
	int i;

	ret = 0;
	str = "";
	i = 0;
	while ((ret = read(fd, buff, BUFF)))
	{
		str = ft_strjoin(str, buff);
		while (buff[i] && i < ret)
		{
			if (buff[i] == '\n')
			{
				buff = newbuff(buff);
				printf("newbuff = [%s]\n", buff);
				return (str);
			}
			i++;
		}
		i = 0;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char buff[BUFF + 1];

	buff[BUFF] = '\0';
	*line = get_first_line(fd, buff);
	printf("buff de get = [%s]\n", buff);
	printf("line  = [%s]\n", *line);
	printf("============================================================\n");
	return (0);
}
int		main()
{
	int fd;
	char **line;
	char *str;

	line = &str;
	fd = open("text4.txt", O_RDONLY);
	get_next_line(fd, line);

	return (0);
}
