/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:15:06 by hmorales          #+#    #+#             */
/*   Updated: 2021/11/26 15:45:37 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (c == 0 && n == 0)
		return (NULL);
	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (*str != c && n-- > 1)
		str++;
	if (*str != c)
		return (NULL);
	return ((char *)str);
}
