
#include "ft_ls.h"

char *str_error_access(char *err, char *path)
{
	char    *error_mess;
	char    *tmp;

	error_mess = ft_strjoin("ft_ls: ", path);
	tmp = error_mess;
	error_mess = ft_strjoin(error_mess, ": ");
	ft_strdel(&tmp);
	tmp = error_mess;
	error_mess = ft_strjoin(error_mess, err);
	ft_strdel(&tmp);
	error_mess = ft_strjoin(error_mess, "\n");
	return(error_mess);
}

void    print_error_access(char *err, char *path)
{
	ft_putendl(str_error_access(err, path));
}

void	print_malloc_error(void)
{
	ft_putendl("malloc error!\n");
	exit(-1);
}

#define STDERROR 2
char *str_error_loop(char *directory, char *file)
{
	char *ret;
	size_t index;

	index = 0;
	ret = ft_strnew(47 + ft_strlen(directory) + strlen(file));
	ft_strcpy(ret, "ft_ls: ");
	index += 7;
	ft_strcpy(ret + index, directory);
	index += ft_strlen(directory);
	ft_strcpy(ret + index, "/");
	index += 1;
	ft_strcpy(ret + index, file);
	index += ft_strlen(file);
	ft_strcpy(ret + index, ": not listing already-listed directory\n");

	//ft_putstr_fd("ft_ls: ", STDERROR);
	//ft_putstr_fd(directory, STDERROR);
	//ft_putstr_fd("/", STDERROR);
	//ft_putstr_fd(file, STDERROR);
	//ft_putstr_fd(": not listing already-listed directory\n", STDERROR);

	return(ret);
}
