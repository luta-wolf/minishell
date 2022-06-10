/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:44:45 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:31:43 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

char	**ft_clear_splitted(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_get_nb_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, size_t *next_len, char c)
{
	size_t	i;

	*next_str += *next_len;
	*next_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	size_t			next_len;
	size_t			nb_strs;
	size_t			i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	tab = malloc(sizeof(char *) * (nb_strs + 1));
	if (!(tab))
		return (NULL);
	i = -1;
	next_str = (char *)s;
	next_len = 0;
	while (++i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_len, c);
		tab[i] = malloc(sizeof(char) * (next_len + 1));
		if (!(tab[i]))
			return (ft_clear_splitted(tab));
		ft_strlcpy(tab[i], next_str, next_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
