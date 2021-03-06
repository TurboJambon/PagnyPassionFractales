/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:51:28 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 21:41:54 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*str1;
	char		*str2;
	size_t		i;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == c)
			return ((char*)&str1[i + 1]);
		i++;
	}
	return (NULL);
}
