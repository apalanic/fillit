/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:06:47 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/21 19:59:32 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	file_open(char *src)
{
	int	fd;

	if (!src)
		return (0);
	fd = open(src, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

static char	*file_read(int fd)
{
	char	*buff;
	int		check_ret;

	buff = ft_memalloc(560);
	if (!buff)
		return (NULL);
	if ((check_ret = read(fd, buff, 560)) == -1)
		return (NULL);
	if ((check_ret = close(fd)) == -1)
		return (NULL);
	return (buff);
}

static char	*filter(char *s)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(sizeof(char) * intstrlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s > 33 && *s != '$')
			ret[i++] = *s;
		s++;
	}
	ret[i] = '\0';
	return (ret);
}

int			main(int ac, char **av)
{
	int		fd;
	int		figure_len;
	char	*content;
	t_fcord	**figs;

	if (ac != 2)
	{
		ft_putendl_fd("usage:\t./fillit target_file", 1);
		return (0);
	}
	fd = file_open(av[1]);
	if (fd && (content = file_read(fd)) && str_is_valid(content))
	{
		content = filter(content);
		figs = get_figure_cord(content, intstrlen(content) / 16 + 1);
		figure_len = intstrlen(content);
		start_algo(figs, ((figure_len + 1) / 16));
	}
	else
	{
		ft_putendl_fd("error", 1);
		return (0);
	}
	return (0);
}
