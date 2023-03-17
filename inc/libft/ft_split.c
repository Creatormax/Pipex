/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:18:52 by hmorales          #+#    #+#             */
/*   Updated: 2021/11/17 17:50:12 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	word_counter(char const *s, char c)
{
	char	*str;
	size_t	word;
	int		i;

	if (!s)
		return (0);
	word = 0;
	i = 0;
	str = (char *)s;
	while (s[word] == c)
		word++;
	if (word == ft_strlen(s))
		return (0);
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

void	update(char **nxtstr, unsigned int *len, char c)
{
	unsigned int	i;

	i = 0;
	*nxtstr += *len;
	*len = 0;
	while (**nxtstr && **nxtstr == c)
		(*nxtstr)++;
	while ((*nxtstr)[i])
	{
		if ((*nxtstr)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**liberator(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	char			*aux;
	unsigned int	col;
	unsigned int	word;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = 0;
	col = -1;
	aux = (char *)s;
	word = word_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (word + 1));
	if (!str)
		return (NULL);
	while (++col < word)
	{
		update(&aux, &len, c);
		str[col] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (liberator(str));
		ft_strlcpy(str[col], aux, len + 1);
	}
	str[col] = NULL;
	return (str);
}
