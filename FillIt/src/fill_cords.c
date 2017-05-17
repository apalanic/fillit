/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:38:50 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/21 17:11:52 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		struct_alloc(int size, t_fcord **figs)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		figs[i] = (t_fcord *)malloc(sizeof(t_fcord));
		j = 0;
		while (++j < 4)
			figs[i]->c[j] = *(t_cord *)malloc(sizeof(t_cord));
	}
}

void		save_cord(int x, int y, t_cord *b)
{
	b->x = x;
	b->y = y;
}

t_fcord		**get_figure_cord(char *cont, int size)
{
	int		f;
	int		sharp;
	int		i;
	int		fp;
	t_fcord	**figs;

	if ((figs = (t_fcord **)malloc(sizeof(t_cord *) * size)) == NULL)
		return (NULL);
	struct_alloc(size, figs);
	f = 0;
	i = -1;
	sharp = 0;
	while (*cont != 0 && ++i > -1)
	{
		if (sharp == 0)
			figs[f]->sym = 'A' + f;
		if (*cont++ == '#' && ++sharp)
		{
			sharp == 1 ? fp = i : 0;
			save_cord(i % 4 - fp % 4, i / 4 - fp / 4, &(figs[f]->c[sharp - 1]));
			if (sharp == 4 && ++f)
				sharp = 0;
		}
	}
	return (figs);
}

int			print_result(char *s)
{
	int dim;
	int row;

	dim = ft_sqrt(intstrlen(s));
	row = -1;
	while (*s != '\0')
	{
		++row;
		if (row == dim)
		{
			ft_putchar_fd('\n', 1);
			row = 0;
		}
		if (*s == '#')
			ft_putchar_fd('A', 1);
		else
			ft_putchar_fd(*s, 1);
		s++;
	}
	exit(1);
	return (0);
}
