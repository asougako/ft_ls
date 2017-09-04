

NAME    = ft_getopt.a
SOURCES = ft_getopt.c ft_getopt_parse.c ft_getopt_print.c
OBJETS  = ft_getopt.o ft_getopt_parse.o ft_getopt_print.o


all: $(NAME)

$(NAME):
		gcc -c $(SOURCES) -I ../libft
		ar rc $(NAME) $(OBJETS)

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)

re: fclean all

proper: fclean all
	rm -f $(OBJETS)
