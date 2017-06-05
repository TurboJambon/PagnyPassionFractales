/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:51:28 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 21:42:03 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rot(char *str, int r)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if (ft_isupper(str[i]))
		{
			new[i] = (((str[i] - 65) + r) % 26) + 65;
			if (new[i] < 0)
				new[i] += 26;
		}
		else if (ft_islower(str[i]))
		{
			new[i] = (((str[i] - 97) + r) % 26) + 97;
			if (new[i] < 0)
				new[i] += 26;
		}
		else
			new[i] = str[i];
		i++;
	}
	return (new);
}
