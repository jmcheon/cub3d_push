/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:05:11 by cjung-mo          #+#    #+#             */
/*   Updated: 2020/01/03 22:37:26 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_next_null(t_list *lst, int n)
{
	t_list	*temp;

	temp = lst;
	while (--n)
		temp = temp->next;
	temp->next = NULL;
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	int		n;

	n = 0;
	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new = ft_lstnew(NULL)))
		return (NULL);
	temp = new;
	while (lst != NULL)
	{
		temp->content = f(lst->content);
		if (!(temp->next = ft_lstnew(NULL)))
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
		n++;
	}
	ft_next_null(new, n);
	return (new);
}
