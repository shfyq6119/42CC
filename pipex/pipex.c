/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:37:09 by mm-isa            #+#    #+#             */
/*   Updated: 2024/03/13 04:24:10 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	proc_out(int *file, char *filename2, char *cmd2, char **env)
{
	int	outfile;
	int	origin;

	outfile = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		exit_error(outfile, NULL, NULL, "no space for outfile");
	origin = dup(STDOUT_FILENO);
	dup2(file[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(file[1]);
	handle_cmd(origin, cmd2, env);
}

void	proc_in(int *file, char *filename1, char *cmd1, char **env)
{
	int	infile;
	int	origin;

	infile = open(filename1, O_RDONLY, 0777);
	if (infile == -1)
		exit_error(infile, NULL, NULL, filename1);
	origin = dup(STDOUT_FILENO);
	dup2(file[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(file[0]);
	handle_cmd(origin, cmd1, env);
}

int	main(int ac, char **av, char **envp)
{
	int	files[2];
	int	child;

	if (ac != 5)
	{
		ft_putstr_fd("argue no enough, more sauce, argue more, MORE!!\n", 2);
		return (0);
	}
	if (ac == 5)
	{
		if (pipe(files) == -1)
			perror("Call the plumber pl00ze");
		child = fork();
		if (child == -1)
			perror("Fork failed, there is no spoon");
		if (child == 0)
			proc_in(files, av[1], av[2], envp);
		waitpid(child, NULL, WNOHANG);
		proc_out(files, av[4], av[3], envp);
	}
	return (0);
}
