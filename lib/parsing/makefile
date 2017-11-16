

NAME    = ft_getopt.a
SOURCES = ft_getopt.c ft_getopt_parse.c ft_getopt_print.c

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
