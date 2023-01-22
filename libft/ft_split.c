/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:01:31 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/01/18 21:44:49 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	count_wrds(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
		i++;
	}
	return (count);
}

static int	wrd_size(char const *wrd, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (wrd[i] == c)
		i++;
	while (wrd[i] && wrd[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static char	**catch_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

static int	ft_j(char const *s, char c, int j)
{
	while (s[j] == c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	str = (char **)malloc((count_wrds(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_wrds(s, c))
	{
		k = 0;
		str[i] = malloc((wrd_size(&s[j], c) + 1) * sizeof(char));
		if (!str[i])
			return (catch_error(str));
		j = ft_j(s, c, j);
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i++][k] = '\0';
	}
	str[i] = NULL;
	return (str);
}
