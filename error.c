
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
        return(error_mess);
}

void    print_error_access(char *err, char *path)
{
	ft_putendl(str_error_access(err, path));
}

void	print_malloc_error(void)
{
		ft_putendl("malloc error!\n");
}
