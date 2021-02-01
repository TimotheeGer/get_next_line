/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:41:28 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/01 12:14:09 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*ft_strdup(const char *s1);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_first_line(int fd, char *buff, char **line, char *temp);
char	*ft_strnew(void);
char	*ft_newrest(char *str);
int		ft_tempavbs(char *temp);
char	*ft_lineintemp(char *temp);
int		get_next_line(int fd, char **line);

#endif
