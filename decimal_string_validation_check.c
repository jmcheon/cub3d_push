/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_string_validation_check.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:04:35 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:04:36 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*decimal_string_validation_check(char **str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen_2dim((const char **)str);
	j = 1;
	while (j < len)
	{
		i = 0;
		while (str[j][i] != '\0')
		{
			if (!ft_isdigit(str[j][i]))
				return (ft_strjoin("Invalid format with : ", str[j]));
			i++;
		}
		j++;
	}
	return (NULL);
}
