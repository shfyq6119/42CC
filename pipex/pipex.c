/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:37:09 by mm-isa            #+#    #+#             */
/*   Updated: 2024/03/24 05:59:24 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	proc_out(int *file, char *filename2, char *cmd2, char **env)
{
	int	outfile;
	int	origin;

	close(file[1]);
	outfile = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		perror(filename2);
	origin = dup(STDOUT_FILENO);
	dup2(file[0], STDIN_FILENO);
	close(file[0]);
	dup2(outfile, STDOUT_FILENO);
	handle_cmd(origin, cmd2, env);
}

void	proc_in(int *file, char *filename1, char *cmd1, char **env)
{
	int	infile;
	int	origin;

	close(file[0]);
	infile = open(filename1, O_RDONLY, 0777);
	if (infile == -1)
		perror(filename1);
	origin = dup(STDOUT_FILENO);
	dup2(file[1], STDOUT_FILENO);
	close(file[1]);
	dup2(infile, STDIN_FILENO);
	handle_cmd(origin, cmd1, env);
}

int	fork_check(int child)
{
	if (child == -1)
		perror("Fork failed, there iz n0 sp00n");
	if (child == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int	files[2];
	int	child1;
	int	child2;

	if (ac < 5)
		ft_putstr_fd("argue no enough, more sauce, argue more, MORE!!\n", 2);
	if (ac > 5)
		ft_putstr_fd("BRO, check args lah.\n", 2);
	if (ac == 5)
	{
		if (pipe(files) == -1)
			perror("Call the plumber pl00ze");
		child1 = fork();
		if (fork_check(child1) == 0)
			proc_in(files, av[1], av[2], envp);
		child2 = fork();
		if (fork_check(child2) == 0)
			proc_out(files, av[4], av[3], envp);
		close(files[0]);
		close(files[1]);
		waitpid(child1, NULL, 0);
		waitpid(child2, NULL, 0);
		return (0);
	}
	return (1);
}
