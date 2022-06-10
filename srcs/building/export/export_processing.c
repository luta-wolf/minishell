/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:49:52 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/07 20:32:07 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strmicrojoin(char **str, char c)
{
	char	*res;
	int		i;
	int		len;

	if ((*str))
		len = ft_strlen((*str));
	else
		len = 0;
	res = malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (len > i)
	{
		res[i] = (*str)[i];
		i++;
	}
	res[i] = c;
	i += 1;
	res[i] = '\0';
	*str = free_tab((void **)str);
	return (res);
}

char	*str_2(char *arg)
{
	char	*new;

	while (*arg && *arg != '=')
		arg++;
	if (!(*arg) || !(*(++arg)))
		return (NULL);
	new = ft_strdup(arg);
	if (!new)
		return (NULL);
	return (new);
}

char	*str(char *arg, int index)
{
	int		i;
	char	*new;

	i = 0;
	if (index == 0)
	{
		while (arg[i] && arg[i] != '=')
			i++;
		if (arg[i] == '=')
			i++;
		new = malloc(sizeof(char) * (i + 1));
		if (!new)
			return (NULL);
		i = -1;
		while (arg[++i] && arg[i - 1] != '=')
			new[i] = arg[i];
		new[i] = '\0';
		return (new);
	}
	return (str_2(arg));
}
