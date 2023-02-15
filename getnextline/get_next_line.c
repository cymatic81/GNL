/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:07:51 by jchapman          #+#    #+#             */
/*   Updated: 2023/01/16 15:28:22 by jchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*getlinefrombuff(char *buffer)
{
	char	*ret;
	int		i;

	i = 0;
	i = linelen(buffer);
	if (i == 0)
		i = gnl_strlen(buffer);
	if (i == 0)
		return (NULL);
	ret = cpyret(buffer, i);
	trimbuff(buffer, i);
	return (ret);
}

static char	*prepbufferforread(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc((gnl_strlen(str) + BUFFER_SIZE + 1) * sizeof str);
	if (!temp)
	{
		str = (NULL);
		return (str);
	}
	if (str != NULL)
	{
		while (str[i])
		{
			temp[i] = str[i];
			i++;
		}	
		free(str);
	}
	temp[i] = '\0';
	return (temp);
}

static int	readfile(char *buffer, int fd)
{
	int	bytesread;
	int	i;

	buffer = prepbufferforread(buffer);
	i = gnl_strlen(buffer);
	bytesread = read(fd, &buffer[i], BUFFER_SIZE);
	if (bytesread < 0)
	{
		free(buffer);
		return (-1);
	}
	buffer[i + bytesread] = '\0';
	return (bytesread);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*ret;
	int			bytesread;

	bytesread = 1;
	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	while (linelen(buffer[fd]) == 0 && bytesread > 0)
	{
		bytesread = readfile(buffer[fd], fd);
		if (bytesread < 0)
			return (NULL);
	}
	ret = getlinefrombuff(buffer[fd]);
	if (bytesread == 0 && buffer[fd] != NULL && gnl_strlen(buffer[fd]) == 0)
	{
		free(buffer[fd]);
		buffer[fd] = (NULL);
	}
	return (ret);
}
