/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:30:50 by cjung-mo          #+#    #+#             */
/*   Updated: 2019/12/09 04:22:43 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src2;

	i = 0;
	src2 = (unsigned char *)src;
	while (i < n)
	{
		if ((unsigned char)c == src2[i])
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
