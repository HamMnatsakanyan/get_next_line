/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:09:58 by hmnatsak          #+#    #+#             */
/*   Updated: 2021/02/18 17:10:01 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	dest = malloc(1 + (ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	i = 0;
	j = 0;
	while ((s1 != NULL && s1[i]) || (s2 != NULL && s2[j]))
	{
		if (s1 != NULL && s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		else
		{
			dest[i + j] = s2[j];
			j++;
		}
	}
	dest[i + j] = '\0';
	free((char *)s1);
	return (dest);
}

int		get_return(char *dst)
{
	int i;

	i = 0;
	if (!dst)
		return (0);
	while (dst[i])
	{
		if (dst[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
