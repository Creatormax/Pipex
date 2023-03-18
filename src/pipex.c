/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:34:36 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/18 17:38:11 by hmorales         ###   ########.fr       */
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

void	pipex(char **argv, char **envp, int *fd, int *i)
{
	int	pid;
	int	status;
	int	count;

	if (*argv)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			execve(pathfinder(argv[*i], envp), argv, envp);
		}
		else
		{
			close(fd[1]);
			count = *i + 1;
			pipex(argv, envp, fd, &count);
		}
		wait(&status);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	*fd;
	int	i;

	i = 1;
	if (argc <= 4)
		ft_errormsg("Number of arguments is invalid\n");
	//printf("numero de args %d", argc);
	arg_checker(argv, argc);
	fd = malloc(2 * sizeof(int) + 1);
	ft_bzero(fd, 2);
	fd[0] = open(argv[1], O_RDONLY);
	pipex(argv, envp, fd, &i);
}

// piensate lo de hacer el bonus de infinitos tiene pinta de ser facil