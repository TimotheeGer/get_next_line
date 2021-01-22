/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:21:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/01/22 13:13:41 by tigerber         ###   ########.fr       */
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

char		*newrest(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (&str[i + 1]);
		}
		i++;
	}
	return (str);
}

int		ft_tempavbs(char *temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char		*get_first_line(int fd, char *buff,char **line,char *temp)
{
	printf("GFL\n");
	int ret;
	int i;
	char *str;

	str = "";
	ret = 0;
	i = 0;
	if (temp != NULL)
	{
		str = ft_strjoin(str, temp);
	}
	while ((ret = read(fd, buff, BUFF)))
	{
		if (ret == 0)
		{
			printf("ret = [%d]\n", ret);
			return (0);
		}
		str = ft_strjoin(str, buff);
		while (buff[i] && i < ret)
		{
			if (buff[i] == '\n')
			{
				*line = str;
				buff = newrest(buff);
				return (buff);
			}
			i++;
		}
		i = 0;
	}
	return (buff);
}

char		*get_temp_line(char *temp, char **line)
{
	printf("GTL\n");
	int i;
	char *str;

	i = 0;
	str = "";
	str = ft_strjoin(str, temp);
	*line = str;
	temp = newrest(temp);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	static char buff[BUFF + 1];
	static char *temp;

	buff[BUFF] = '\0';
	if (temp == NULL)
	{
		temp = get_first_line(fd, buff, line, temp);
		printf ("temp GFL = [%s]\n", temp);
		return (1);
	}
	if ((temp != NULL) && (ft_tempavbs(temp) == 0))
	{
		temp = get_first_line(fd, buff, line, temp);
		printf ("temp GFL = [%s]\n", temp);
		return (1);
	}
	if (temp != NULL && ft_tempavbs(temp))
	{
		temp = get_temp_line(temp, line);
		printf ("temp GTL = [%s]\n", temp);
		return (1);
	}
	return (0);
}
int		main()
{
	int fd;
	char **line;
	char *str;

	line = &str;
	fd = open("text4.txt", O_RDONLY);
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
}
