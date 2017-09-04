# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asougako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:26:49 by asougako          #+#    #+#              #
#    Updated: 2017/06/01 19:08:46 by asougako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, proper
.SUFFIXES:

NAME = libft.a
CC = gcc
CF = -Wall -Wextra -Werror
AR = ar
DEBUG = 0
ifeq ($(DEBUG), 1)
	DF = -g
else
	DF =
endif
RM = /bin/rm -f
HEAD_DIR = ./
SRC_DIR = ./src/
SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_intlen.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_islower.c\
		ft_isprint.c\
		ft_isspace.c\
		ft_isupper.c\
		ft_itoa.c\
		ft_uitoa.c\
		ft_itoabase.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putnstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtab_add.c\
		ft_strtab_dup.c\
		ft_strtab_len.c\
		ft_strtab_new.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstadd_tail.c\
		ft_strndup.c\
		ft_lstdelif.c\
		ft_lstchr.c\
		ft_dict_new.c\
		ft_dict_add.c\
		ft_dict_del.c\
		ft_dict_find.c\
		ft_dict_print.c\
		get_next_line.c\
		ft_print_memory.c\
		ft_lowstr.c\
		ft_uppstr.c


OBJ = $(SRC:.c=.o)
ECHO = echo
OS = $(shell uname -s)
ifeq ($(OS), Linux)
ECHO = echo -e
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rc $(NAME) $^
ifeq ($(DEBUG), 1)
	@$(ECHO) "Created library \033[32m$@\033[0m with debug flag."
else
	@$(ECHO) "Created library \033[32m$@\033[0m."
endif

%.o: %.c
	@$(CC) $(DF) $(CF) -c $(SRC_DIR)$^ -I $(HEAD_DIR)
	@$(ECHO) "Created object \033[32m$@\033[0m."

clean:
	@$(RM) $(OBJ)
	@$(ECHO) "Removing \033[31mobjects\033[0m."

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "Removing \033[31m$(NAME)\033[0m."

re: fclean all

proper: fclean all
	@$(RM) $(OBJ)
	@$(ECHO) "Removing \033[31mobjects\033[0m."
