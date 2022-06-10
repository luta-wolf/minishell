/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:46:06 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:34:26 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

int	ft_strncmp(char *str1, char *str2, unsigned int size)
{
	unsigned int	x;

	x = 0;
	while (x < size && ((str1[x]) || (str2[x])))
	{
		if ((unsigned char)str1[x] < (unsigned char)str2[x])
			return (-1);
		else if ((unsigned char)str1[x] > (unsigned char)str2[x])
			return (1);
		x++;
	}
	return (0);
}
