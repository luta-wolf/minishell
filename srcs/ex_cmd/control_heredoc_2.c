/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_heredoc_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:48:24 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/07 20:36:44 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	unsigned int	i;

	i = 0;
	while ((str1[i]) || (str2[i]))
	{
		if ((unsigned char)str1[i] < (unsigned char)str2[i])
			return (-1);
		else if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_sort(char **str, char **res, int option, int *tub)
{
	close(tub[OUT]);
	dup2(tub[IN], 1);
	close(tub[IN]);
	if (option == 0)
		check_var_env(res);
	write(1, (*res), ft_strlen((*res)));
	*str = free_tab((void **)str);
	*res = free_tab((void **)res);
	exit(0);
	return (1);
}

int	ft_join(char **res, char *str)
{
	char	*tmp;

	tmp = ft_strdup(*res);
	*res = free_tab((void **)res);
	if (!tmp)
		*res = ft_strdup(str);
	else
		*res = ft_strjoin(tmp, str);
	tmp = free_tab((void **)&tmp);
	tmp = ft_strdup(*res);
	*res = free_tab((void **)res);
	*res = ft_strjoin(tmp, "\n");
	tmp = free_tab((void **)&tmp);
	return (1);
}

int	clearing_quotes(char **str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	if ((*str)[0] == '\"' && (*str)[1] == '\0')
		return (2);
	if ((*str)[0] == '\'' && (*str)[1] == '\0')
		return (2);
	while ((*str)[i])
	{
		if ((*str)[i] == '\"' || (*str)[i] == '\'')
			sub_char(str, i);
		else
			i++;
	}
	return (0);
}

int	ft_heredoc(char *deb, char *fin, int option, int *tub)
{
	char	*str;
	char	*res;
	char	*tmp;
	int		verif;

	str = NULL;
	res = NULL;
	tmp = NULL;
	(void)option;
	verif = clearing_quotes(&fin);
	verif += clearing_quotes(&deb);
	while (1)
	{
		str = readline(GRN"Heredoc>"RESET);
		if (deb == NULL && ft_strcmp(fin, str) == 0 && verif == 0)
			ft_sort(&str, &res, option, tub);
		else if (deb == NULL && ft_strcmp(fin, str) == 0 && verif != 0)
			ft_sort_2(&str, &res, option, tub);
		else if (deb == NULL && str)
			ft_join(&res, str);
		else if (deb != NULL && ft_strcmp(deb, str) == 0)
			deb = NULL;
		str = free_tab((void **)&str);
	}
}
