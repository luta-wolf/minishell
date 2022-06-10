/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:47:17 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 19:45:19 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char		**ft_strdoublejoin(char **tab, char *str);
char		*ft_strdup(char *src);
int			ft_strlen(char *str);
int			ft_strncmp(char *str1, char *str2, unsigned int size);
int			ft_strlcpy(char *dst, char *src, unsigned int size);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_whitespace(char cara);
char		**ft_strdoubledup(char **tab);

#endif
