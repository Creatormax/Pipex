/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:12:46 by hmorales          #+#    #+#             */
/*   Updated: 2022/01/15 18:13:10 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*liberator(char *aux)
{
	free (aux);
	return (NULL);
}

static inline int	buffer_checker(char *str, char **aux)
{
	char	*lb;
	char	aux2[BUFFER_SIZE + 1];
	char	*aux3;

	lb = ft_strchr(str, '\n');
	if (lb)
	{
		*lb = '\0';
		ft_bzero(aux2, BUFFER_SIZE + 1);
		ft_memcpy(aux2, lb + 1, ft_strlen(lb + 1));
		aux3 = *aux;
		*aux = ft_strjoin(aux3, str);
		free (aux3);
		aux3 = *aux;
		*aux = ft_strjoin(aux3, "\n");
		free (aux3);
		ft_bzero(str, BUFFER_SIZE + 1);
		ft_memcpy(str, aux2, ft_strlen(aux2));
		return (1);
	}
	aux3 = *aux;
	*aux = ft_strjoin(aux3, str);
	free (aux3);
	ft_bzero(str, BUFFER_SIZE + 1);
	return (0);
}

char	*get_next_line(int fd)
{
	char			*aux;
	static char		str[BUFFER_SIZE + 1];
	int				rch;

	aux = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || !aux || fd < 0 || fd > 256)
		return (liberator(aux));
	ft_bzero(aux, BUFFER_SIZE);
	if (buffer_checker(str, &aux) == 1)
		return (aux);
	rch = read(fd, str, BUFFER_SIZE);
	while (rch >= 1)
	{
		if (buffer_checker(str, &aux) == 1)
			return (aux);
		rch = read(fd, str, BUFFER_SIZE);
	}
	if (aux[0] == '\0')
		return (liberator(aux));
	return (aux);
}
