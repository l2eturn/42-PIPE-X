/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 01:25:36 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/18 01:25:36 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER 4242

# include "../libft/libft.h"
# include "../src/pipex.h"
# include "../libft/get_next_line.h"

void				arg_err(void);
int					fd_for_file(char *av, int i);
void				child_process_bonus(char *av, char **envp);
char				*stdin_line(char **line);

#endif
