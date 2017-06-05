/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:51:29 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 21:42:11 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] && i < n)
		i++;
	j = i;
	if (!n)
		return (ft_strlen(s2) + j);
	while (s2[i - j] && i < n - 1)
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (j < n)
	{
		s1[i] = '\0';
	}
	return (ft_strlen(s2) + j);
}
