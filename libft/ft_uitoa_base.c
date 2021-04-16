/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:34:41 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/01/22 11:36:48 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_uitoa_base_nsize(unsigned long n, int rad)
{
	int				len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= rad;
		len++;
	}
	return (len);
}

char				*ft_uitoa_base(unsigned long n, char *base)
{
	unsigned long	temp;
	long			i;
	int				rad;
	char			*s;

	rad = ft_strlen(base);
	i = ft_uitoa_base_nsize(n, rad);
	temp = n;
	if (!(s = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	s[i] = 0;
	while (temp >= 1 && i >= 0)
	{
		s[--i] = base[(temp % rad)];
		temp /= rad;
	}
	return (s);
}
