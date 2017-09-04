

NAME    = ft_options.a
SOURCES = ft_options.c
OBJETS  = ft_options.o


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
