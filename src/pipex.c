/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:34:36 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/17 18:15:40 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

void	arg_checker(char **argv, int argc)
{
	char	*str;
	int		n;
	int		fd;

	n = 1;
	while (n < argc)
	{
		str = argv[n];
		if ((n == 1) || (n == argc))
		{
			fd = open(argv[n], O_RDONLY);
			if (!fd || fd < 0 || fd > 256)
				ft_errormsg("File does not exist");
			close(fd);
		}
		else
		{
			str = ft_strcleaner(str, '"');
			argv[n] = str;
		}
		n++;
	}
}

void	pathfinder(void)
{
	
}

void	pipex(char **argv, char **envp, int* fd)
{
	int	pid;
	int	status;
	char	*path;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	*fd;

	if (argc <= 5)
		ft_errormsg("Number of arguments is invalid\n");
	//printf("numero de args %d", argc);
	arg_checker(argv, argc);
	ft_bzero(fd, 3);
	fd[2] = open(argv[1], O_RDONLY);
}

// piensate lo de hacer el bonus de infinitos tiene pinta de ser facil