/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:40:29 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/27 20:23:52 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		sqr(int nb)
{
	return (nb * nb);
}

int				ft_sqrt(int nb)
{
	int			result;
	int			start;
	int			finish;

	start = 0;
	finish = 46342;
	while (1)
	{
		result = (finish + start) / 2;
		if (sqr(result) > nb)
			finish = result;
		else if (sqr(result) < nb)
			start = result;
		if (sqr(result) == nb)
			return (result);
		if ((finish - start) <= 1)
		{
			return (0);
		}
	}
}
