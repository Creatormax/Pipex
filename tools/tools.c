/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:42:45 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/31 15:08:55 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

char	*strcut(char* str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i++;
	str[i] = '\0';
	return (str);
}

int	strcutlen(char* str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

char	*pathfinder(char *str, char **envp)
{
	int		check;
	int		i;
	char	*command;
	char	**envp_path;

	i = 0;
	check = -1;
	if (str[0] == '/' || str[0] == '.')
		return (str);
	else
	{
		envp_path = ft_split(envp[2], ':');
		envp_path[0] = ft_memmove(envp_path[0], envp_path[0] + 5, \
		ft_strlen(envp_path[0]) - 5);
		str = strcut(str, ' ');
		while ((check == -1) && envp_path[i])
		{
			command = ft_strjoin(ft_strjoin(envp_path[i], "/"), str);
			i++;
			check = access(command, X_OK);
		}
		return (command);
	}
}
