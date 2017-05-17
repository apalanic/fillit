/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:13:11 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/22 11:49:39 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_cord
{
	char			x;
	char			y;
}					t_cord;

typedef struct		s_fcord
{
	struct s_cord	c[4];
	char			sym;
}					t_fcord;

int					print_result(char *s);
int					intstrlen(char *s);
int					str_is_valid(char *s);
int					figure_is_valid(char *s);
void				struct_alloc(int size, t_fcord **figs);
int					first_sqr(int len);
char				*resize(char *field);
void				start_algo(t_fcord **figs, int len);
char				*fill_wdots(int len);
t_fcord				**remove_figure(t_fcord **figs, int len, int i);
t_fcord				**get_figure_cord(char *cont, int size);
int					figure_check(char *s);
int					ft_sqrt(int nb);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strdup(const char *s);
void				*ft_memalloc(size_t size);
void				*ft_bzero(void *s, size_t n);

#endif
