/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:39:42 by cjung-mo          #+#    #+#             */
/*   Updated: 2019/12/10 21:30:18 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	temp;
	char	c;

	temp = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		temp = temp * (-1);
	}
	if (temp >= 10)
		ft_putnbr_fd(temp / 10, fd);
	c = (temp % 10) + '0';
	write(fd, &c, 1);
}
