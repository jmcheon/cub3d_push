/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:51:00 by cjung-mo          #+#    #+#             */
/*   Updated: 2019/12/11 02:45:53 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_hm(char const *s, char c)
{
	size_t	nbr;
	size_t	i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i] && s[i - 1] == c)
			nbr++;
		if (s[i])
			i++;
	}
	if (nbr == 0 && s[i - 1] == c)
		return (0);
	if (s[0] != c)
		nbr++;
	return (nbr);
}

static char		**ft_mal(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	h;
	size_t	cnt;

	cnt = 0;
	i = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c)
			cnt++;
		else if (h > 0 && s[h - 1] != c)
		{
			strs[i] = malloc(sizeof(char) * (cnt + 1));
			if (!strs[i])
				return (0);
			cnt = 0;
			i++;
		}
		if (s[h + 1] == '\0' && s[h] != c)
			if (!(strs[i] = malloc(sizeof(char) * cnt + 1)))
				return (0);
		h++;
	}
	return (strs);
}

static void	i_copy(char **strs, char const *s, char c)
{
	size_t	h;
	size_t	i;
	size_t	j;

	h = 0;
	i = 0;
	j = 0;
	while (s[h])
	{
		if (s[h] != c)
			strs[i][j++] = s[h];
		else if (h > 0 && s[h - 1] != c)
		{
			if (h != 0)
			{
				strs[i][j] = '\0';
				j = 0;
				i++;
			}
		}
		if (s[h + 1] == '\0' && s[h] != c)
			strs[i][j] = '\0';
		h++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	nbr_w;

	if (!s || !*s)
	{
		if (!(ret = malloc(sizeof(char *) * 1)))
			return (NULL);
		*ret = (void *)0;
		return (ret);
	}
	nbr_w = ft_hm(s, c);
	ret = malloc(sizeof(char *) * (nbr_w + 1));
	if (!ret)
		return (0);
	if (ft_mal(ret, s, c) != 0)
		i_copy(ret, s, c);
	else
	{
		ft_memdel(ret);
		return (NULL);
	}
	ret[nbr_w] = (void *)0;
	return (ret);
}
