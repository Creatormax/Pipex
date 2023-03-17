/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:03:47 by hmorales          #+#    #+#             */
/*   Updated: 2021/11/12 15:02:00 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (!size)
		return (ft_strlen(src));
	while (i < l && i < size)
	{
		if (i < size - 1)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	if (l <= size - 1)
		dest[i] = 0;
	return (ft_strlen(src));
}
