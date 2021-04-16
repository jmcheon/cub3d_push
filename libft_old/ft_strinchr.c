/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:01:21 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/05 12:02:11 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strinchr(const char *s, char c)
{
	char *str;

	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
