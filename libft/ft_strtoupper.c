/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:51:29 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 21:42:21 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		new[i] = ft_toupper(str[i]);
		i++;
	}
	return (new);
}
