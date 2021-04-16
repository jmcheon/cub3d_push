/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:26:14 by cjung-mo          #+#    #+#             */
/*   Updated: 2019/12/19 17:25:07 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	temp = (*lst);
	if (*lst != NULL && del != NULL)
	{
		while (temp != NULL)
		{
			next = temp->next;
			del(temp->content);
			free(temp);
			temp = next;
		}
	}
	*lst = NULL;
}
