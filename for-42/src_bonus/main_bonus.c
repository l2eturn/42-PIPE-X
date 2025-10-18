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

static void	write_heredoc_input(char *limiter, int write_fd)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& (line[ft_strlen(limiter)] == '\n'
				|| line[ft_strlen(limiter)] == '\0'))
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

void	here_doc(char *limiter)
{
	pid_t	reader;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	reader = fork();
	if (reader == -1)
		error();
	if (reader == 0)
	{
		close(fd[0]);
		write_heredoc_input(limiter, fd[1]);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(reader, NULL, 0);
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
			fileout = open_file(av[ac - 1], 0);
			here_doc(av[2]);
		}
		else
		{
			i = 2;
			fileout = open_file(av[ac - 1], 1);
			filein = open_file(av[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < ac - 2)
			child_process_bonus(av[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(av[ac - 2], envp);
	}
	arg_err();
}
