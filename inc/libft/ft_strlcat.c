/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:25:51 by hmorales          #+#    #+#             */
/*   Updated: 2021/11/11 13:23:22 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	i;

	i = 0;
	d = ft_strlen(dest);
	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && d + 1 < size)
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
