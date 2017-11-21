.PHONY: clean, re
.SUFFIXES:

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Werror -Wextra
ASAN = -fsanitize=address -fno-omit-frame-pointer
INCLUDE = -I lib/
LIB = 	lib/parsing/ft_getopt.a\
		lib/libft/libft.a
RM = /bin/rm -f
ECHO = echo -e
#	|		|		|		|
SRC =	ft_ls.c		options.c	argv_sort.c	error.c\
	process_file.c	print.c		sort.c		sort_ctime.c\
	sort_name.c	sort_size.c	sort_atime.c	sort_mtime.c\
	sort_no.c	sort_btime.c


all: $(NAME)

$(NAME):
	@$(CC) $(SRC) $(FLAGS) $(INCLUDE) $(LIB) -o $(NAME)
	@$(ECHO) "Compile $(NAME)."

debug:
	@$(CC) -g $(SRC) $(FLAGS) $(INCLUDE) $(LIB) -o $(NAME)
	@$(ECHO) "Compile $(NAME) in debug mode."

noflags:
	@$(CC) -g $(SRC) $(INCLUDE) $(LIB) -o $(NAME)
	@$(ECHO) "Compile $(NAME) without flags."

sanitize:
	@$(CC) -g $(ASAN) $(SRC) $(INCLUDE) $(LIB) -o $(NAME)
	@$(ECHO) "Compile $(NAME) without flags."

clean:
	@$(RM) $(NAME)
	@$(ECHO) "Remove $(NAME)"

re: clean all

