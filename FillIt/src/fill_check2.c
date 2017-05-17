/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:44:31 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/21 15:33:40 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	sharp_check(const char *s)
{
	int		sharp_cnt;
	int		i;

	sharp_cnt = 0;
	i = 0;
	while (i < 20)
	{
		if (*s == '#')
			sharp_cnt++;
		s++;
		i++;
	}
	if (sharp_cnt != 4)
		return (0);
	return (1);
}

static int	dots_check(const char *s)
{
	int		dot_cnt;
	int		i;

	dot_cnt = 0;
	i = 0;
	while (i < 20)
	{
		if (*s == '.')
			dot_cnt++;
		s++;
		i++;
	}
	if (dot_cnt == 12)
		return (1);
	return (0);
}

static int	newline_check(const char *s)
{
	int i;

	i = 1;
	while (i < 21)
	{
		if (i % 5 == 0)
		{
			if (*s != '\n')
				return (0);
		}
		i++;
		s++;
	}
	return (1);
}

int			figure_is_valid(char *s)
{
	if (!sharp_check(s))
		return (0);
	if (!dots_check(s))
		return (0);
	if (!newline_check(s))
		return (0);
	if (figure_check(s) != 4)
		return (0);
	return (1);
}
