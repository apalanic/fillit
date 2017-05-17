/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:07:53 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/21 15:30:06 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	form_check(char *s, int pos, int cntr, int shift)
{
	if (s[pos - 1] == '#' && cntr != 4)
	{
		cntr++;
		if (pos < 16 && cntr != 4 && shift != -5)
			cntr = form_check(s, pos + 5, cntr, 5);
		if (pos > 5 && cntr != 4 && shift != 5)
			cntr = form_check(s, pos - 5, cntr, -5);
		if (pos % 5 != 1 && cntr != 4 && shift != 1)
			cntr = form_check(s, pos - 1, cntr, -1);
		if (pos % 5 != 4 && cntr != 4 && shift != -1)
			cntr = form_check(s, pos + 1, cntr, 1);
	}
	return (cntr);
}

int			figure_check(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == '#')
			return (form_check(s, i + 1, 0, 0));
	return (0);
}

static int	check_nline(char *ch)
{
	if (*ch == '\n')
	{
		*ch = '$';
		return (1);
	}
	return (0);
}

int			str_is_valid(char *s)
{
	if (!s)
		return (0);
	if (!(*s == '.' || *s == '#'))
		return (0);
	while (*s)
	{
		if (!figure_is_valid(s))
			return (0);
		s += 20;
		if (*s == '\0')
			return (1);
		if (!check_nline(s))
			return (0);
		s++;
	}
	if (*s == '\0' && *(s - 1) == '$' && *(s - 2) == '\n')
		return (0);
	return (1);
}
