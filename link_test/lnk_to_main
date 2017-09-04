
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define MAX_PATH_LENGHT 1024

ssize_t	get_link(char *path, char **buff);

int		main(int argc, char **argv)
{
		char 	*buff;

		if (argc != 2)
		{
				printf("usage: a.out link_path");
				return(-1);
		}

		buff = NULL;
		ft_print_memory(buff, get_link(*(argv + 1), &buff) + 1);
		ft_memdel((void**)&buff);

		return(0);
}

ssize_t	get_link(char *path, char **buff)
{
		ssize_t read_size;
		int		buff_size = 0;
		int		errsv;

		buff_size = 0x01;
		*buff = ft_strnew(buff_size);
		while(buff_size <= MAX_PATH_LENGHT)
		{
				if ((read_size = readlink(path, *buff, buff_size)) != buff_size)
				{
						errsv = errno;
						break;
				}
				buff_size <<= 1;
				ft_memdel((void**)buff);
				*buff = ft_strnew(buff_size);
		}
		if (read_size < 0)
		{
				//call file_error() instead
				printf("error: %s\n", strerror(errsv));
		}
		return(read_size);
}
