/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:02:05 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/01/22 02:40:02 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**real_path(char **env)
{
	char	**p;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			p = ft_split(env[i] + 5, ':');
			return (p);
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char **cmd, char **env)
{
	char	*path;
	char	*cmd_file;
	char	**full_path;
	int		i;

	full_path = real_path(env);
	if (!full_path)
		ft_err("pipex: command not found: ", cmd[0]);
	cmd_file = ft_strjoin("/", cmd[0]);
	i = -1;
	while (full_path[++i])
	{
		path = ft_strjoin(full_path[i], cmd_file);
		if (!access(path, F_OK | X_OK))
			return (ft_free(full_path), free(cmd_file), path);
		free(path);
	}
	ft_free(full_path);
	return (NULL);
}
