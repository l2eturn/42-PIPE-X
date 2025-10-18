/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 01:26:12 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/18 01:26:12 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process_bonus(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		xcq(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int ac)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (ac < 6)
		arg_err();
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (stdin_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = fd_for_file(av[ac - 1], 0);
		}
		else
		{
			i = 2;
			fileout = fd_for_file(av[ac - 1], 1);
			filein = fd_for_file(av[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < ac - 2)
			child_process_bonus(av[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		xcq(av[ac - 2], envp);
	}
	arg_err();
}
