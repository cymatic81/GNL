/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:56:29 by jchapman          #+#    #+#             */
/*   Updated: 2023/02/28 15:05:51 by jchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	linelen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*cpyret(char *str, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((len + 1) * sizeof str);
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*trimbuff(char *str)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = gnl_strlen(str);
	temp = malloc((i + 1) * sizeof str);
	while (str[i + j])
	{
		temp[j] = str[i + j];
		j++;
	}	
	temp[j] = '\0';
	free (str);
	return (temp);
}

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*freebuff(char *str)
{
	free(str);
	str = NULL;
	return (str);
}
