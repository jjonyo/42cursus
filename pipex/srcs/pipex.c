/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:54:07 by jonghpar          #+#    #+#             */
/*   Updated: 2022/02/27 20:54:34 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(int *fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	close(infile);
	execute(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(outfile);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid Arguments", 2);
		return (0);
	}
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		child_process(fd, argv, envp);
	else if (pid > 0)
	{
		waitpid(pid, NULL, WNOHANG);
		parent_process(fd, argv, envp);
	}
	return (0);
}
