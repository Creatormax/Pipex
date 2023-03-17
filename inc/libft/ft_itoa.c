/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:53:13 by hmorales          #+#    #+#             */
/*   Updated: 2021/11/17 21:44:45 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int	digits(int n)
{
	unsigned int	i;
	int				nb;

	i = 1;
	if (n < 0)
		i = 2;
	nb = n / 10;
	while (nb != nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	char			*nbr;
	int				nb;

	i = digits(n);
	nbr = (char *)malloc(sizeof(char) * i + 1);
	if (!nbr)
		return (NULL);
	nb = n;
	nbr[i] = '\0';
	while (i-- > 0)
	{
		if (nb < 0)
			nbr[i] = -(nb % 10) + '0';
		else
			nbr[i] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
