/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:56:30 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/17 17:56:30 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	parent_process(char **av,char **envp,int *fd)
{

}

void	child_process(char **av,char **envp,int *fd)
{
	int	file_in;

	file_in = open(av[1], O_RDONLY, 0777);
	if (file_in == -1)
		error();
	close(fd[0]);
	dup2(file_in, STDIN_FILENO);
	close(file_in);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

int main(int ac, char **av, char **envp)
{
	int	fd[2];
	pid_t pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(av, envp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			parent_process(av, envp, fd);
		}
	}
	else
	{
		ft_putstr_fd("Bad arguments\n",2);
		ft_putstr_fd("eg: ./pipex <infile> <cmd1> <cmd2> <outfile>\n",1);
	}
}
