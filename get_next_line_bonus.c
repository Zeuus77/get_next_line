/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:55:48 by youel-id          #+#    #+#             */
/*   Updated: 2022/11/30 23:55:50 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"


char *get_line_from_save(char *save)
{
	if(!save[0])
	{
		return NULL;
	}
	int i;
	char *ret;

	i = 0;

	while(save[i] && save[i] != '\n')
		i++;
	if(save[i] && save[i] == '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	if(!ret)
		return 0;
	i = 0;
	while(save[i] && save[i] !=  '\n')
	{
		ret[i] = save[i];
		i++;
	}
	if(save[i] && save[i] == '\n')
	  	ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}
char *update_save(char *save)
{
	int i = 0;
	int j = 0;
	char *new_save;
	while(save[i] && save[i] != '\n')
		i++;
	if(!save[i])
	{
		free(save);
		return(NULL);
	}
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(save) - i ) + 1);
	i++;
	while(save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return(new_save);
}
char *get_next(char *save,int fd, char *buffer)
{
	int rd;

	rd = 1;
	while (rd > 0 )
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(save);
			save = NULL;
			free(buffer);
			return NULL;
		}
		buffer[rd] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n'))
			break;
	}
	free(buffer);
	return(save);
}
char *get_next_line(int fd)
{
	char *buffer;
	static char *save[OPEN_MAX];
	char *line;
	if(fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return(NULL);
	save[fd] = get_next(save[fd],fd,buffer);
	if(!save[fd])
		return(NULL);
	
	line = get_line_from_save(save[fd]);
	save[fd]= update_save(save[fd]);
	return (line);
}
/*int main()
{
	int fd = open("file.txt",O_RDONLY);
	int fd1 = open("file1.txt",O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd1));
    
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
}*/
