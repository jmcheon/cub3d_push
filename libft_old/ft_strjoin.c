/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:43:50 by cjung-mo          #+#    #+#             */
/*   Updated: 2019/12/11 02:46:28 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	int		i;
	int		len1;

	i = -1;
	len1 = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(dst = (char *)malloc((ft_strlen(s1)
	+ ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[len1])
	{
		dst[len1] = s1[len1];
		len1++;
	}
	while (++i < (int)ft_strlen(s2))
		dst[len1 + i] = s2[i];
	dst[len1 + i] = 0;
	return (dst);
}
