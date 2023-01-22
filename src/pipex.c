/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:58:47 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/01/22 02:14:16 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_wait(int *fd, pid_t *pid, char **av)
{
	int	status;

	(void) av;
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	free(fd);
	free(pid);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		exit(WTERMSIG(status) + 128);
}

int	main(int ac, char **av, char **env)
{
	int		*fd;
	int		i;
	pid_t	*pid;

	if (ac != 5)
		ft_error("Number of argument is invalid");
	fd = (int *)malloc(2 * sizeof(int));
	pid = (pid_t *)malloc(2 * sizeof(pid_t));
	i = pipe(fd);
	ft_check(i);
	pid[0] = fork();
	ft_check(pid[0]);
	if (pid[0] == 0)
		ft_child1(fd, av, env);
	pid[1] = fork();
	ft_check(pid[1]);
	if (pid[1] == 0)
		ft_child2(fd, av, env);
	close_wait(fd, pid, av);
	return (0);
}
