# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 14:32:56 by lde-moul          #+#    #+#              #
#    Updated: 2017/03/13 14:54:03 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./
OBJDIR = objs
INCDIR = includes

SRCBASE =  ft_printf.c\
		   format.c\
		   flags.c\
		   width.c\
		   precision.c\
		   conversion.c\
		   conflict.c\
		   padding.c\
		   number.c\
		   print_decimal.c\
		   print_hexadecimal.c\
		   print_octal.c\
		   print_signed.c\
		   print_string.c\
		   print_wstring.c\
		   print_char.c\
		   print_wchar.c\
		   print_pointer.c\
		   unicode.c\

SRC = $(SRCBASE:%=$(SRCDIR)/%)
OBJ = $(SRCBASE:%.c=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.c:
	/bin/echo $@ does not exist.

$(OBJDIR):
	/bin/mkdir $(OBJDIR)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
