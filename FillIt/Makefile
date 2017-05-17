# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apalanic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/21 19:23:37 by apalanic          #+#    #+#              #
#    Updated: 2016/12/21 20:00:29 by apalanic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	fill_algo.c \
		fill_check.c \
		fill_check2.c \
		fill_cords.c \
	   	fill_funcs.c \
		fillit.c \
		ft_sqrt.c \
		ft_putendl_fd.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_memalloc.c \
		ft_bzero.c \


SRCDIR = ./src/
OBJDIR = ./obj/

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c 
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
