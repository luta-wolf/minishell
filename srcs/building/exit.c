/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:52:38 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/07 20:35:10 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ex_exit(int nbr, int err, char *str)
{
	printf("exit\n");
	if (err == 1)
	{
		write (2, "shell: exit: ", 17);
		write(2, str, ft_strlen(str));
		write(2, ": numeric argument required\n", 29);
	}
	if (err == 2)
		write (2, "shell: exit: too many arguments\n", 37);
	listing(g_term.cmd);
	free_all(0);
	exit (nbr);
}

int	verif_arg(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) == 1 || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				ex_exit(2, 1, str);
			i++;
		}
		return (0);
	}
	else
		ex_exit(2, 1, str);
	return (-1);
}

long long	ft_atoll(char *str)
{
	int			i;
	int			sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (((i == 18 && sign == 1) && (str[i] > '7' && str[i] <= '9'))
			|| ((i == 19 && sign == -1) && (str[i] > '8'))
			|| (i > 18 && sign == 1) || (i > 19 && sign == -1)
			|| (i == 18 && str[17] > '0' && sign == 1)
			|| (i == 18 && str[18] > '0' && sign == -1))
			ex_exit(2, 1, str);
		i++;
	}
	return (sign * nbr);
}

void	ft_exit(char **argv)
{
	long long	nbr;

	nbr = 0;
	if (!(argv[1]))
		ex_exit(g_term.dernier_ret, 0, NULL);
	else if (argv[2])
		ex_exit(1, 2, NULL);
	verif_arg(argv[1]);
	nbr = ft_atoll(argv[1]);
	ex_exit(nbr, 0, NULL);
}
