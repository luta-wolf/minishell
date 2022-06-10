/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_building.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:33:31 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/07 20:34:05 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_building(t_cmd *cmd)
{
	if (!cmd->cmd)
		return (0);
	if (ft_strncmp(cmd->cmd, "cd", 10) == 0
		|| ft_strncmp(cmd->cmd, "unset", 10) == 0
		|| ft_strncmp(cmd->cmd, "export", 10) == 0
		|| ft_strncmp(cmd->cmd, "exit", 10) == 0
		|| ft_strncmp(cmd->cmd, "pwd", 10) == 0
		|| ft_strncmp(cmd->cmd, "echo", 10) == 0
		|| ft_strncmp(cmd->cmd, "env", 10) == 0)
		return (1);
	return (0);
}
