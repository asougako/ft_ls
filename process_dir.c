
#include "ft_ls.h"


#define FILE_NAME name
#define FILE_NAME_ISNT(name) ft_strcmp(FILE_NAME, name)
int     is_printable(char *name)
{
    if (opt_a)
    {
        return(true);
    }
    else if (opt_A)
    {
        if (FILE_NAME_ISNT(".") != 0 && FILE_NAME_ISNT("..") != 0)
        {
            return(true);
        }
    }
    else if (*(name + 0) != '.')
    {
        return(true);
    }
    return(false);
}
#undef FILE_NAME
#undef FILE_NAME_ISNT

#define FILE_NAME (*direntry).d_name
void    read_dir(char **dir)
{
	DIR         *dirstream;
	t_dirent    *direntry;
	t_list      *file_lst;
	t_list      *error_lst;
	t_stat      fstat;
	char        *path;
	int         (*stat_func)(const char *restrict, struct stat *restrict);


	dirstream = NULL;
	direntry = NULL;
	error_lst = NULL;
	file_lst = NULL;
	//fstat = NULL;
	path = NULL;
	if (opt_L)
	{
		stat_func = &stat;
	}
	else
	{
		stat_func = &lstat;
	}
	if ((dirstream = opendir(*dir)) == NULL)
	{
		ft_putendl_fd(str_error_access(strerror(errno), *dir), 2);
		return;
	}
	while ((direntry = readdir(dirstream)) != NULL)
	{
		if (is_printable(FILE_NAME))
		{
			path = path_join(*dir, FILE_NAME);
			if (stat_func(path, &fstat) != 0)
			{
				add_error(&error_lst, strerror(errno), path);
			}
			else
			{
				add_file(&file_lst, &fstat, *dir, FILE_NAME);
			}
			ft_strdel(&path);
		}
	}
	closedir(dirstream);
	if (file_lst != NULL)
		print_file_lst(file_lst);
	if (error_lst != NULL)
		print_error_lst(error_lst);
	recursive(file_lst);
	ft_lstdel(&error_lst, errlst_destructor);
	ft_lstdel(&file_lst, lst_destructor);
}
#undef FILE_NAME

void    process_dirs(char **argv, int argc, int index)
{
	t_stat      fstat;
	int         (*stat_func)(const char *restrict, struct stat *restrict);


	if (opt_L || opt_H)
		stat_func = &stat;
	else
		stat_func = &lstat;

	while(*argv)
	{
		if (stat_func(*argv, &fstat) != 0);
		else if (S_ISDIR(fstat.st_mode) && !(opt_d))
		{
			if (index > 1 || (argc - ft_optind) >= 2)
			{
				if (index != 0)
					ft_putendl("");
				ft_putstr(*argv);
				ft_putendl(":");
			}
			check_loop(fstat.st_ino, RESET);
			read_dir(argv);
			index++;
		}
		argv++;
	}
}
