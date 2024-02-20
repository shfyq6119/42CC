/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:37:09 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/25 07:08:01 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void proc_intake(int fd[2], char *file, char *cmd, char **envp)
{
	int 	fd_open;
	int		execmd;
	int		pid;
	char	*path;

	pid = fork();
	if (pid == -1)
		perror("Fork failed BODOH");
	else if (pid)
	{
		close(fd[0]); //close read end of pipe; i.e. close itself (fd[0]) so it does not wait to read from here.
		fd_open = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_open == -1)
			perror("intake file failed BENGAP.");
		dup2(fd[1], STDOUT_FILENO); // dup child's fd 
		dup(fd_open, STDIN_FILENO);
	}
}

int	main(int ac, char **av, char **envp)
{
	int fd[2];

	if (ac != 5)
	{
		write(1, "argue no enough, more sauce, argue MORE, MORE!!\n", 48);
		return (0);
	}
	if (pipe(fds) == -1)
		write(1, "Pipe Error siol\n", 11);
	proc_intake(fd, av[1], av[2], envp);
	wait(NULL);
	process_out(fd, av[3], av[4], envp);
	close(fd[0]);
	close(fd[1]);
	return (0);
