/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:09:44 by hmnatsak          #+#    #+#             */
/*   Updated: 2021/02/18 17:09:46 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *rtd)
{
	int		i;
	char	*str;

	i = 0;
	if (!rtd)
		return (0);
	while (rtd[i] && rtd[i] != '\n')
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (rtd[i] && rtd[i] != '\n')
	{
		str[i] = rtd[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_src(char *rezerv)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	if (!rezerv)
		return (0);
	while (rezerv[i] && rezerv[i] != '\n')
		i++;
	if (!rezerv[i])
	{
		free(rezerv);
		return (0);
	}
	if (!(str = (char *)malloc(sizeof(char) * ((ft_strlen(rezerv) - i) + 1))))
		return (0);
	i++;
	while (rezerv[i])
		str[j++] = rezerv[i++];
	str[j] = '\0';
	free(rezerv);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*src;
	int			s;

	s = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!get_return(src) && s != 0)
	{
		if ((s = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[s] = '\0';
		src = ft_strjoin(src, buff);
	}
	free(buff);
	*line = ft_line(src);
	src = ft_src(src);
	if (s == 0)
		return (0);
	return (1);
}
