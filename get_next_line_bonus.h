/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:33:43 by youel-id          #+#    #+#             */
/*   Updated: 2022/12/01 00:33:48 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 50
#endif

#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(const char *str);
char *get_line_from_save(char *save);
char *update_save(char *save);
char	*ft_strjoin(char  *s1, char *s2);
char *get_next_line(int fd);
int	ft_strchr(char *str, char c);
char *get_next(char *save,int fd, char *buffer);

#endif
