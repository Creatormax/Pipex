/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:39:16 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/20 13:55:02 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		new->prior = NULL;
		return ;
	}
	aux = ft_lstlast(*lst);
	if (aux && *lst && new)
	{
		aux->next = new;
		new->prior = aux;
	}
}
