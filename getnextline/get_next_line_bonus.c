/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:07:51 by jchapman          #+#    #+#             */
/*   Updated: 2023/03/03 14:37:27 by jchapman         ###   ########.fr       */
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
	return (ret);
}

static char	*prepbufferforread(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc((gnl_strlen(str) + BUFFER_SIZE + 1) * sizeof str);
	if (!temp)
		return (NULL);
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			temp[i] = str[i];
			i++;
		}	
	}
	temp[i] = '\0';
	if (str != NULL)
		free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4095];
	char		*ret;
	int			bytesread;
	int			i;

	bytesread = 1;
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	while (linelen(buffer[fd]) == 0 && bytesread > 0)
	{
		buffer[fd] = prepbufferforread(buffer[fd]);
		i = gnl_strlen(buffer[fd]);
		bytesread = read(fd, &buffer[fd][i], BUFFER_SIZE);
		if (bytesread < 0)
		{
			buffer[fd] = freebuff(buffer[fd]);
			return (NULL);
		}
		buffer[fd][i + BUFFER_SIZE] = '\0';
	}
	ret = getlinefrombuff(buffer[fd]);
	buffer[fd] = trimbuff(buffer[fd]);
	if (bytesread <= 0 && buffer[fd] != NULL && gnl_strlen(buffer[fd]) == 0)
		buffer[fd] = freebuff(buffer[fd]);
	return (ret);
}
