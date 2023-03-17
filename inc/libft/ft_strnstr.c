/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:45:21 by hmorales          #+#    #+#             */
/*   Updated: 2022/09/21 10:57:18 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	char	*b;
	char	*l;

	j = 0;
	l = (char *)little;
	b = (char *)big;
	if (!l || !b)
		return (b);
	while (*b != 0 && len > 0)
	{
		while (b[j] == l[j] && b[j] && l[j] && j < len)
			j++;
		if (l[j] == 0)
			return (b);
		j = 0;
		b++;
		len--;
	}
	return (0);
}
