/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:37 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:33:48 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	len;

	len = 0;
	x = 0;
	if (src == NULL)
		return (0);
	while (src[len])
		len++;
	if (size > 0)
	{
		while (x < size - 1 && src[x])
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (len);
}
