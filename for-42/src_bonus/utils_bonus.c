/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 01:26:10 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/18 01:26:10 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	arg_err(void)
{
	ft_putstr_fd("Bad argument", 2);
	ft_putstr_fd("eg: ./pipex_bonus <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("./pipex_bonus <here_doc> <LIMITER> <cmd> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	fd_for_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(av, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
}

char	*stdin_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	ch;

	i = 0;
	r = 0;
	buffer = (char *)malloc(BUFFER);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\0' && c != '\n')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i ++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	i++;
	buffer[i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
