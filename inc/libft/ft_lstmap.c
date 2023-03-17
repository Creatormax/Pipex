/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:09:04 by hmorales          #+#    #+#             */
/*   Updated: 2022/07/04 12:08:12 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;

	last = 0;
	while (lst)
	{
		first = ft_lstnew(f(lst->content));
		if (!first)
		{
			ft_lstclear(&last, del);
			return (0);
		}
		ft_lstadd_back(&last, first);
		lst = lst->next;
	}
	return (last);
}
