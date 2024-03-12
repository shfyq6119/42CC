/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:29:03 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/12 21:37:35 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <locale.h>
# include <errno.h>

# include "lib_ft/libft/libft.h"
# include "lib_ft/ft_printf/ft_printf.h"

void	proc_in(int *file, char *filename1, char *cmd1, char **env);
void	proc_out(int *file, char *filename2, char *cmd2, char **env);
void	handle_cmd(int original, char *cmd_raw, char **env);
void	clean_cache(char **junk);
void	exit_error(int original, char **arr, char *str, char const *msg);
char	**cmd_parse(char *cmd_raw);
char	*pathfinder(char *cmd, char **envp);

#endif
