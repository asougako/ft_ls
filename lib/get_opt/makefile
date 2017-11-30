# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asougako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 12:17:40 by asougako          #+#    #+#              #
#    Updated: 2017/11/30 12:17:46 by asougako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = ft_getopt.a
SOURCES = ft_getopt.c

OBJETS  = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
		gcc -c $(SOURCES) -I ../
		ar rc $(NAME) $(OBJETS) ../libft/libft.a

debug:
		gcc -c -g $(SOURCES) -I ../
		ar rc $(NAME) $(OBJETS) ../libft/libft.a

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)

re: fclean all

proper: fclean all
	rm -f $(OBJETS)
