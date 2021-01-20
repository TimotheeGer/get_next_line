/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:17:19 by tigerber          #+#    #+#             */
/*   Updated: 2021/01/20 15:40:35 by tigerber         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * ft_strlen((char*)s1) + 1)))
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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

int		get_next_line(int fd, char **line)
{
	static char buf[BUFF + 1];
	int i;
	static char *str;
	//static char *str2;
	int ret;
	char *temp;

	buf[BUFF] = '\0';
	//str = "";
	i = 0;
	ret = 0;
	printf("str = [%s]\n", str);
	while ((ret = read(fd, buf, BUFF)))
	{
		str = ft_strjoin(str, buf);
		printf("strjoin = [%s]\n", str);
		while (buf[i] != '\0' && i < ret)
		{
			if (ret == 0)
			{
				return (0);
			}
			if (buf[i] == '\n')
			{
				temp = ft_strdup(&buf[i + 1]);
				printf("temp = [%s]\n", temp);
				*line = str;
				str = ft_strdup(temp);
				printf("strdup = [%s]\n", str);
				return (1);
			}
			i++;
		}


		i = 0;
	}
	return (0);
}

int		main()
{
	char **line;
	char **temp;
	char *str;
	int fd;

	line = &str;
	temp = NULL;
	fd = open("text.txt", O_RDONLY);
	//get_next_line(fd, line);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("get1 = %d\n\n", get_next_line(fd, line));
	printf("str main = [%s]\n\n", str);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("get2 = %d\n\n", get_next_line(fd, line));
	printf("str main = [%s]\n\n", str);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("get3 = %d\n\n", get_next_line(fd, line));
	printf("str main = [%s]\n\n", str);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("get4 = %d\n\n", get_next_line(fd, line));
	printf("str main = [%s]\n\n", str);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("get5 = %d\n\n", get_next_line(fd, line));
	printf("str main = [%s]\n\n", str);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	return (0);
}
