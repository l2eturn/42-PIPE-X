/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:46:53 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/17 19:46:53 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*env_path(char *cmd, char **envp)
{
	int		i;
	char	**path_in_envp;
	char	*add_slash;
	char	*abs_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i ++;
	path_in_envp = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_in_envp[i])
	{
		add_slash = ft_strjoin(path_in_envp[i], "/");
		abs_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(abs_path, F_OK) == 0)
			return (abs_path);
		free(abs_path);
		i ++;
	}
	i = -1;
	while (path_in_envp[++i])
		free(path_in_envp[i]);
	free(path_in_envp);
	return (0);
}

void	xcq(char *command_line, char **envp)
{
	char	**cmd;
	char	*abs_path;
	int		i;

	cmd = ft_split(command_line, ' ');
	abs_path = env_path(cmd[0], envp);
	if (!abs_path)
	{
		i = 0;
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error();
	}
	if (execve(abs_path, cmd, envp) == -1)
		error();
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
