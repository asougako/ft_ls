
#include "ft_ls.h"

void    print_error_access(char *err, char *path)
{
        char    *error_mess;
        char    *tmp;

        error_mess = ft_strjoin("ft_ls", ": cannot access ");
        tmp = error_mess;
        error_mess = ft_strjoin(error_mess, path);
        ft_strdel(&tmp);
        tmp = error_mess;
        error_mess = ft_strjoin(error_mess, ": ");
        ft_strdel(&tmp);
        tmp = error_mess;
        error_mess = ft_strjoin(error_mess, err);
        ft_putendl(error_mess);
        ft_strdel(&tmp);
        ft_strdel(&error_mess);
}

void	print_malloc_error(void)
{
		ft_putendl("malloc error!\n");
}
