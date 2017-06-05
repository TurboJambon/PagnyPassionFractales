/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:51:29 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 21:42:16 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = malloc(sizeof(char) * size + 1);
	if (!(s))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
