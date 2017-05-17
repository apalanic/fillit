/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:12:26 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/21 19:22:05 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		intstrlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int		first_sqr(int len)
{
	int i;

	i = 1;
	while (i * i < len)
		i++;
	return (i * i);
}

char	*resize(char *field)
{
	int		dimention;
	char	*nfield;
	int		i;

	dimention = 1 + ft_sqrt(intstrlen(field));
	if ((nfield = (char *)malloc(dimention * dimention + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < (dimention * dimention))
		nfield[i] = '.';
	nfield[i] = '\0';
	return (nfield);
}

char	*fill_wdots(int len)
{
	char	*ret;
	int		i;
	int		size;

	size = first_sqr(len * 4);
	if ((ret = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = '.';
	ret[i] = '\0';
	return (ret);
}

t_fcord	**remove_figure(t_fcord **figs, int len, int i)
{
	t_fcord	**new_figs;
	int		j;
	int		m;

	if (len == 1)
		return (figs);
	if ((new_figs = (t_fcord **)malloc(sizeof(t_cord *) * len - 1)) == NULL)
		return (NULL);
	struct_alloc(len - 1, new_figs);
	j = -1;
	m = 0;
	while (++j < len)
	{
		if (j == i)
			m = -1;
		else
			new_figs[j + m] = figs[j];
	}
	return (new_figs);
}
