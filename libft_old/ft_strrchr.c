/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:04:20 by cjung-mo          #+#    #+#             */
/*   Updated: 2019/12/07 00:28:25 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;
	char	*str;

	i = 0;
	last = -1;
	str = (char *)s;
	if ((char)c == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	while (str[i])
	{
		if (str[i] == (char)c)
			last = i;
		i++;
	}
	if (last != -1)
		return ((char *)(s + last));
	return (NULL);
}
