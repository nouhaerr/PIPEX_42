/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:33:58 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/01/22 03:43:10 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	cmd_slash(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	ft_child1(int *fd, char **av, char **env)
{
	int		input;
	char	*path;
	char	**cmd;

	input = open(av[1], O_RDONLY);
	if (input == -1)
	{
		perror(av[1]);
		exit(127);
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	cmd = ft_split(av[2], ' ');
	path = cmd[0];
	if (!cmd_slash(cmd[0]))
		path = get_path(cmd, env);
	ft_arg2(av);
	if (!path)
		ft_err("pipex: command not found: ", cmd[0]);
	dup2(input, STDIN_FILENO);
	close(input);
	ft_execve(path, cmd, env);
}

void	ft_child2(int *fd, char **av, char **env)
{
	int		output;
	char	*path;
	char	**cmd;

	output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output == -1)
	{
		perror(av[4]);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	cmd = ft_split(av[3], ' ');
	path = cmd[0];
	if (!cmd_slash(cmd[0]))
		path = get_path(cmd, env);
	ft_arg3(av);
	if (!path)
		ft_err("pipex: command not found: ", cmd[0]);
	dup2(output, STDOUT_FILENO);
	close(output);
	ft_execve(path, cmd, env);
}
