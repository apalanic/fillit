/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:26:59 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/21 19:16:17 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*put_fig(t_fcord f, char *field, int j)
{
	int dim;
	int i;
	int pos;

	i = -1;
	dim = ft_sqrt(intstrlen(field));
	while (++i < 4)
	{
		pos = j + f.c[i].y * dim + f.c[i].x;
		if (i > 0)
			if (f.c[i].y == f.c[i - 1].y && f.c[i].x == f.c[i - 1].x + 1 &&
				(pos % dim) == 0)
				return (0);
		if (pos >= 0 && pos < intstrlen(field) && field[pos] == '.')
		{
			if ((pos >= pos - (pos % dim)) && pos < pos + (dim - (pos % dim)))
				field[pos] = f.sym;
			else
				return (0);
		}
		else
			return (0);
	}
	return (field);
}

char	*fill_algo(t_fcord **figs, char *field, int len)
{
	int		i;
	int		j;
	char	*nfield;
	char	*tmp;

	len == 0 ? print_result(field) : 0;
	tmp = ft_strdup(field);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < intstrlen(field))
			if (field[j] == '.')
			{
				if (put_fig(*figs[i], field, j))
				{
					nfield = field;
					len == 1 ? print_result(nfield) : 0;
					fill_algo(remove_figure(figs, len, i), nfield, len - 1);
				}
				else
					field = ft_strdup(tmp);
			}
	}
	return (0);
}

void	start_algo(t_fcord **figs, int len)
{
	int		i;
	int		j;
	char	*field;
	char	*nfield;
	char	*tmp;

	field = fill_wdots(len);
	while ((i = -1) == -1)
	{
		tmp = ft_strdup(field);
		while (++i < len)
		{
			j = -1;
			while (++j < intstrlen(field))
				if ((field = put_fig(*figs[i], field, j)))
				{
					nfield = field;
					fill_algo(remove_figure(figs, len, i), nfield, len - 1);
				}
				else
					field = ft_strdup(tmp);
		}
		field = resize(field);
	}
}
