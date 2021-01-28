/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:21:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/01/26 15:48:14 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char		*get_first_line(int fd, char *buff,char **line,char *temp)
{
	int ret;
	int i;
	char *str;

	str = "";
	ret = 0;
	i = 0;
	if (temp != NULL)
		str = ft_strjoin(str, temp);
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		str = ft_strjoin(str, buff);
		while (buff[i] && i < ret)
		{
			if (buff[i] == '\n')
			{
				*line = str;
				buff = ft_strndup(buff, ret);
				buff = newrest(buff);
				return (buff);
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}

char		*get_temp_line(char *temp, char **line)
{
	int i;
	char *str;

	i = 0;
	str = ft_strjoin("", temp);
	*line = str;
	temp = newrest(temp);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE + 1];
	static char *temp;

	buff[BUFFER_SIZE] = '\0';
	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || read(fd, buff, 0))
		return (-1);
	if (temp == NULL)
	{
		if (!(temp = get_first_line(fd, buff, line, temp)))
			return (0);
		return (1);
	}
	if ((temp != NULL) && (ft_tempavbs(temp) == 0))
	{
		if (!(temp = get_first_line(fd, buff, line, temp)))
			return (0);
		return (1);
	}
	if (temp != NULL && ft_tempavbs(temp))
	{
		temp = get_temp_line(temp, line);
		return (1);
	}
	return (0);
}
/*
int		main()
{
	int fd;
	char **line;
	char *str;
	int i = 0;

	line = &str;
	fd = open("text.txt", O_RDONLY);
	while ((get_next_line(fd, line) > 0))
	{
		printf("[%d][%s]\n",i, *line);
		printf("******************************************************************************************************\n");
		i++;
	}
	printf("============================================================\n");
	printf("getnextline 1 = %d\n", get_next_line(fd, line));
	printf("line = [%s]\n", *line);
	printf("============================================================\n");
	printf("getnextline 2  = %d\n", get_next_line(fd, line));
	printf("line = [%s]\n", *line);
	printf("============================================================\n");
	printf("getnextline 3 = %d\n", get_next_line(fd, line));
	printf("line = [%s]\n", *line);
	printf("============================================================\n");
	printf("getnextline 4 = %d\n", get_next_line(fd, line));
	printf("line = [%s]\n", *line);
	printf("============================================================\n");
	printf("getnextline 5 = %d\n", get_next_line(fd, line));
	printf("line = [%s]\n", *line);
	printf("============================================================\n");
	return (0);
}*/
