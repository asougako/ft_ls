
#include "ft_ls.h"

void	print_error_malloc(int err_no)
{
	ft_putendl_fd(strerror(err_no), 2);
	exit(EXIT_FAILURE);
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
