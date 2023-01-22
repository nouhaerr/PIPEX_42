/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:29:40 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/01/22 02:46:49 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_arg2(char **av)
{
	if (!av[2][0])
	{
		ft_putendl_fd("pipex: permission denied:", STDERR_FILENO);
		exit(126);
	}
}

void	ft_arg3(char **av)
{
	if (!av[3][0])
	{
		ft_putendl_fd("pipex: permission denied:", STDERR_FILENO);
		exit(126);
	}
}

void	ft_execve(char *path, char **cmd, char **env)
{
	if (execve(path, cmd, env) < 0)
	{
		perror("execve");
		exit(1);
	}
}
