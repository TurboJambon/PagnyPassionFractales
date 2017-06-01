/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:39:18 by niragne           #+#    #+#             */
/*   Updated: 2016/11/29 20:39:19 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}
