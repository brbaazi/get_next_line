/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:58:58 by brbaazi           #+#    #+#             */
/*   Updated: 2024/12/14 12:12:56 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*newline(char *str)
{
	int		i;
	char	*newstr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		newstr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static char	*lastline(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!newstr)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		newstr[j++] = str[i++];
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

static char	*ft_read(int fd, char *savestr)
{
	char	*buff;
	ssize_t	readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(savestr, '\n') && readbytes != 0)
	{
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(buff);
			free(savestr);
			return (NULL);
		}
		buff[readbytes] = '\0';
		savestr = ft_strjoin(savestr, buff);
	}
	free(buff);
	return (savestr);
}

char	*get_next_line(int fd)
{
	static char	*savestr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savestr = ft_read(fd, savestr);
	if (!savestr)
		return (NULL);
	line = newline(savestr);
	savestr = lastline(savestr);
	return (line);
}
