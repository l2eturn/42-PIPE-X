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
