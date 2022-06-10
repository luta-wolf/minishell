/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdoublejoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:04:02 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:32:56 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

char	**ft_strdoublejoin(char **tab, char *str)
{
	char	**res;
	int		len;

	len = 0;
	res = NULL;
	while (tab && tab[len])
		len++;
	res = malloc(sizeof(char *) * (len + 2));
	if (!res)
		return (NULL);
	len = 0;
	while (tab && tab[len])
	{
		res[len] = ft_strdup(tab[len]);
		len++;
	}
	if (str)
		res[len] = ft_strdup(str);
	len++;
	res[len] = NULL;
	return (res);
}

char	**ft_strdoubledup(char **tab)
{
	char	**res;
	int		len;

	len = 0;
	res = NULL;
	if (!tab)
		return (NULL);
	while (tab && tab[len])
		len++;
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	len = 0;
	while (tab && tab[len])
	{
		res[len] = ft_strdup(tab[len]);
		len++;
	}
	res[len] = NULL;
	return (res);
}
