/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:26:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/01/28 15:58:51 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
size_t  ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s && s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_lineintemp(char *temp)
{
	char *str;
	int i;
	int j;

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

char	*ft_strndup(char *str, int len)
{
	int i;
	char *dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_newrest(char *str)
{
	char *dest;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str && str[i] != '\n' && str[i] != '\n')
	{
		i++;
	}
	if (!(dest = malloc(sizeof(char) * ft_strlen(&str[i + 1]) + 1)))
		return (0);
	while (str[i])
	{
		dest[j] = str[i + 1];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int		ft_tempavbs(char *temp)
{
	int i;

	i = 0;
	while (temp && temp[i])
	{
		if (temp[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	char			*tempo;
	static char		*temp;
	static int 		ret;
	int 			i;

	i = 0;
	ret = 0;
	if (!temp)
		temp = ft_strndup("", 1);
	while ((!(ft_tempavbs(temp))) && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{printf("while\n");
		buff[ret] = '\0';
		tempo = temp;
		temp = ft_strjoin(temp, buff);
		free(tempo);
		if (ft_tempavbs(temp))
		{
			*line = ft_lineintemp(temp);
			tempo = temp;
			temp = ft_newrest(temp);
			free(tempo);
			return (1);
		}
	}
	if (ft_tempavbs(temp))
	{
		*line = ft_lineintemp(temp);
		temp = ft_newrest(temp);
		return (1);
	}
	if (ret == 0)
	{
		*line = temp;
	//	free(temp);
	//	return (0);
	}
	return (0);
}

int main()
{
	char *line= NULL;
	int fd;
	int i = 0;

	fd = open("text.txt", O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
	{
		printf("gnl[%d]=[%s]\n", i, line);
		i++;
	}
	printf("gnl1 = [%d]\n", get_next_line(fd, &line));
	printf("line = [%s]\n", line);
	/*printf("gnl1 = [%d]\n", get_next_line(fd, &line));
	printf("line = [%s]\n", line);
	printf("===========================================================================\n");
	printf("gnl2 = [%d]\n", get_next_line(fd, &line));
	printf("line = [%s]\n", line);
	printf("===========================================================================\n");
	free(line);*/
	//sleep(120);
	return (0);
}
