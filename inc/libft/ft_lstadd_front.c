/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:15:12 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/20 13:02:55 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst && new)
	{
		*lst = new;
		new->next = NULL;
		new->prior = NULL;
		return ;
	}
	if (lst && new)
	{
		new->next = *lst;
		(*lst)->prior = new;
		*lst = new;
		new->prior = NULL;
	}
}
