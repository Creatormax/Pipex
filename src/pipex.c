/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:34:36 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/31 15:17:28 by hmorales         ###   ########.fr       */
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

void	pipex(char **argv, char **envp, int *fd1, int *i)
{
	int	pid;
	int	status;
	int	*fd2;

	fd2 = malloc(2 * sizeof(int) + 1);
	ft_bzero(fd2, 2);
	if (argv[*i + 2])
	{
		pipe(fd1);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd1[0], STDIN_FILENO);
			close(fd1[0]);
			dup2(fd2[1], STDOUT_FILENO);
			close(fd2[1]);
			execve(pathfinder(argv[*i], envp), argv, envp);
			
		}
		else
		{
			close(fd1[1]);
			close(fd2[0]);
			*i = *i + 1;
			//pipex(argv, envp, fd2, &(*i));
		}
		free(fd2);
		wait(&status);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	*fd;
	int	i;

	i = 2;
	if (argc <= 4)
		ft_errormsg("Number of arguments is invalid\n");
	arg_checker(argv, argc);
	fd = malloc(2 * sizeof(int) + 1);
	ft_bzero(fd, 2);
	fd[0] = open(argv[1], O_RDONLY);
	pipex(argv, envp, fd, &i);
}

// piensate lo de hacer el bonus de infinitos tiene pinta de ser facil