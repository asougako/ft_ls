
#include "ft_ls.h"

void	print_error_malloc(int err_no)
{
	ft_putendl_fd(strerror(err_no), 2);
	exit(EXIT_FAILURE);
}

void	print_error_loop(char *file)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": directory causes a cycle", 2);
}

char	*str_error_access(char *err, char *file)
{
	size_t	index;
	char	*buff;

	index = 0;
	buff = ft_strnew(sizeof(*buff) * ft_strlen(err) + ft_strlen(file) + 666);
	ft_strcpy(buff + index, "ft_ls: ");
	index += 7;
	ft_strcpy(buff + index, file);
	index += ft_strlen(file);
	ft_strcpy(buff + index, ": ");
	index += 2;
	ft_strcpy(buff + index, err);
	return(buff);
}

void	print_error_access(char *err, char *file)
{
	char *buff;

	buff = NULL;
	buff = str_error_access(err, file);
	ft_putendl_fd(buff, 2);
	ft_strdel(&buff);
}
