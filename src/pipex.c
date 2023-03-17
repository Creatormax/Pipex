/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:34:36 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/17 17:46:54 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

void	arg_checker(char **arg, int argc)
{
	char	*str;
	int		n;
	int		fd;

	n = 1;
	while (n < argc)
	{
		str = arg[n];
		if ((n == 1) || (n == argc))
		{
			fd = open(arg[n], O_RDONLY);
			if (!fd || fd < 0 || fd > 256)
				ft_errormsg("File does not exist");
			close(fd);
		}
		else
		{
			str = ft_strcleaner(str, '"');
			arg[n] = str;
		}
		n++;
	}
}

void	pipex(char **argv, char **envp, int fd_in, int fd_out)
{
	int	pid;
	int	status;
	
}

int	main(int argc, char **argv, char **envp)
{
	if (argc <= 5)
		ft_errormsg("Number of arguments is invalid\n");
	//printf("numero de args %d", argc);
	arg_checker(argv, argc);
}

// piensate lo de hacer el bonus de infinitos tiene pinta de ser facil