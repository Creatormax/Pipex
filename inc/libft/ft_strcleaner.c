/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:33:53 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/17 15:31:34 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcleaner(char *str, char c)
{
	int		size;
	int		i;
	int		n;
	char	*copy;

	i = 0;
	size = ft_strlen(str);
	while((i < size) && (str[i] != '\0'))
	{
		if (str[i] == c)
		{
			copy = ft_memcpy(copy, str, i);
			n = i;
			while (n > 0)
			{
				(*str)++;
				n--;
			}
			str = ft_strjoin(copy, str);
		}
		i++;
	}
	return (str);
}