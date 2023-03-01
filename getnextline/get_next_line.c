/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:07:51 by jchapman          #+#    #+#             */
/*   Updated: 2023/02/28 17:39:53 by jchapman         ###   ########.fr       */
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
	temp = str;
	str = malloc((gnl_strlen(str) + BUFFER_SIZE + 1) * sizeof str);
	if (!str)
	{
		return (NULL);
	}
	if (temp != NULL)
	{
		while (temp[i])
		{
			str[i] = temp[i];
			i++;
		}	
		free(temp);
	}
	str[i] = '\0';
	return (str);
}

static int	readfile(char *buffer, int fd)
{
	int	bytesread;
	int	i;

	buffer = prepbufferforread(buffer); //is this buffer is outta scope of static **buffer
	i = gnl_strlen(buffer);
	bytesread = read(fd, &buffer[i], BUFFER_SIZE);
	printf("BB%s\n", buffer);
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
	printf("AA%s\n", buffer[fd]);
	ret = getlinefrombuff(buffer[fd]);
	if (bytesread == 0 && buffer[fd] != NULL && gnl_strlen(buffer[fd]) == 0)
	{
		free(buffer[fd]);
		return (NULL);
	}
	return (ret);
}
