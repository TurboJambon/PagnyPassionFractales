/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:51:29 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 21:42:17 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] && (i < len))
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k] && (j < len))
		{
			j++;
			k++;
			if (!s2[k])
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
