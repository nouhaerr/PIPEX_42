/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:59:32 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/01/22 02:49:31 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>

void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	ft_free(char **str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

void	ft_check(int p);
void	ft_arg2(char **av);
void	ft_arg3(char **av);
void	ft_execve(char *path, char **cmd, char **env);
void	ft_error(char *s);
char	**real_path(char **env);
char	*get_path(char **cmd, char **env);
int		access_file(char *av);
void	ft_err(char *s, char *cmd);
void	ft_child1(int *fd, char **av, char **env);
void	ft_child2(int *fd, char **av, char **env);

#endif
