/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:42:45 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/18 17:52:27 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

char	*pathfinder(char *str, char **envp)
{
	int		check;
	int		i;
	char	*command;
	char	**envp_path;

	i = 0;
	check = 1;
	if (str[0] == '/' || str[0] == '.')
		return (str);
	else
	{
		envp_path = ft_split(envp[2], ':');
		ft_memmove(envp_path[0], envp_path[0] + 5, \
		ft_strlen(envp_path[0]) - 5);
		while (check != 0)
		{
			command = ft_strjoin(envp_path[i], str);
			i++;
			check = access(command, X_OK);
		}
		return (command);
	}
}

//char	*commandfinder(char *str)
//{
//	char	**matrix;
//	int		i;
//
//	i = 0;
//	matrix = malloc();
//	ft_loadmatrix('\0', *matrix);
//	matrix = ft_split(str, '/');
//	while (*matrix[i])
//		i++;
//	return (matrix[i]);
//}