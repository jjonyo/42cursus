/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:05:45 by jonghpar          #+#    #+#             */
/*   Updated: 2022/02/26 17:44:28 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	perror("Error: ");
	exit(1);
}

char	*find_path(char *command, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	if (access(command, F_OK) == 0)
		return (command);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	*path;
	char	**command;

	command = ft_split(argv, ' ');
	path = find_path(command[0], envp);
	if (!path)
	{
		ft_putstr_fd("Error: command not found", 2);
		exit(0);
	}
	if (execve(path, command, envp) == -1)
		error();
}
