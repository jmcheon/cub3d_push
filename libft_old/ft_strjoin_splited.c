/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_splited.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:05:19 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/05 12:05:21 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_combined_total_length(const char **splited)
{
	int		i;
	int		len;
	int		total;

	len = 0;
	total = 0;
	while (splited[len] != NULL)
	{
		i = 0;
		while (splited[len][i] != '\0')
			i++;
		total += i;
		len++;
	}
	return (total);
}

char	*ft_strjoin_splited(const char **splited)
{
	char	*dst;
	int		i;
	int		j;
	int		len;
	int		total;

	len = 0;
	j = 0;
	total = ft_combined_total_length(splited);
	if (!(dst = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (splited[len] != NULL)
	{
		i = 0;
		while (splited[len][i] != '\0' && j < total)
		{
			dst[j] = splited[len][i];
			i++;
			j++;
		}
		len++;
	}
	dst[j] = '\0';
	return (dst);
}
