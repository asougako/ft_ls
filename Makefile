
NAME = ft_ls

SRC = ft_ls.c\
	  help.c\
	  process.c\
	  process_file.c\
	  append.c\
	  macro_test.c\
	  print_dir.c\
	  print_short.c\
	  error.c\
	  sort.c\
	  sort_name.c\
	  sort_size.c\
	  sort_atime.c\
	  sort_ctime.c\
	  sort_mtime.c

LIB = lib42/options/ft_getopt.a\
	  lib42/libft/libft.a

INC = -I lib42

FLAGS = -Werror -Wextra -Wall

all:
	gcc $(INC) $(SRC) $(LIB) $(FLAGS)

noflags:
	gcc $(INC) $(SRC) $(LIB)

debug:
	gcc -g $(INC) $(SRC) $(LIB)

verbose:
	gcc -v $(INC) $(SRC) $(LIB)
