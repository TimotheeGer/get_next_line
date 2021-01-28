/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:30:12 by tigerber          #+#    #+#             */
/*   Updated: 2021/01/27 16:40:08 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <libc.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*get_first_line(int fd, char *buff, char **line, char *temp);
char	*get_temp_line(char *temp, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strndup(char *str, int len);
char	*newrest(char *str);
int		ft_tempavbs(char *temp);
int		get_next_line(int fd, char **line);

#endif
