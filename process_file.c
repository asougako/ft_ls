
#include "ft_ls.h"

#define FILE_STAT (*(t_xstat*)(*file_link).content).stat
#define FILE_PATH (*(t_xstat*)(*file_link).content).path
#define FILE_NAME (*(t_xstat*)(*file_link).content).name
#define FILE_XATTR (*(t_xstat*)(*file_link).content).xattr
#define FILE_XASIZE (*(t_xstat*)(*file_link).content).xa_size
#define FILE_ERROR (*(t_xstat*)(*file_link).content).file_error
void	add_error(t_list **error_lst, char *err, char *file)
{
    char        *error;
    t_list      *error_link;

    error = str_error_access(err, file);
    if ((error_link = ft_lstnew(error, ft_strlen(error))) == NULL)
        print_error_malloc(errno);
    ft_lstadd_tail(error_lst, error_link);
}

static void	get_xattr(t_list *file_link, char *path)
{
    if (OPT(L))
    	FILE_XASIZE = listxattr(path, NULL, 0, 0);
    else
    	FILE_XASIZE = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    if (FILE_XASIZE < 0)
    {
     //   printf("get_xattr(): listxattr: error\n");
	//FILE_XATTR = ft_strdup((strerror(errno)));
	FILE_XATTR = NULL;
	return;
    }
    if (FILE_XASIZE == 0)
	return;
    FILE_XATTR = ft_strnew(FILE_XASIZE);
    if (OPT(L))
    	FILE_XASIZE = listxattr(path, FILE_XATTR, FILE_XASIZE, 0);
    else
    	FILE_XASIZE = listxattr(path, FILE_XATTR, FILE_XASIZE, XATTR_NOFOLLOW);
    if (FILE_XASIZE < 0)
    {
       // printf("get_xattr(): listxattr: error\n");
	//FILE_XATTR = ft_strdup((strerror(errno)));
	FILE_XATTR = NULL;
	return;
    }
}

void    add_file(t_list **file_lst, t_stat *fstat, char *dir, char *file)
{
    t_list      *file_link;
    t_xstat	*xfs;

    xfs = NULL;
    xfs = (t_xstat*)ft_memalloc(sizeof(*xfs));
    if ((file_link = ft_lstnew(NULL, sizeof(t_xstat*))) == NULL)
        print_error_malloc(errno);
    (*file_link).content = xfs;
    FILE_STAT = (t_stat*)ft_memdup(fstat, sizeof(*fstat));
    if (dir != NULL)
    	FILE_PATH = ft_strdup(dir);
    FILE_NAME = ft_strdup(file);
    if (OPT(e))
    	get_xattr(file_link, path_join(dir, file));
    ft_lstsort(file_lst, file_link);
}
#undef FILE_STAT
#undef FILE_PATH
#undef FILE_NAME
#undef FILE_XATTR
#undef FILE_ERROR

void    process_files(char **argv)
{
    t_stat      fstat;
    t_list      *file_lst;
    t_list      *error_lst;
    int         (*stat_func)(const char *restrict, struct stat *restrict);

    file_lst = NULL;
    error_lst = NULL;

    if (OPT(L))
        stat_func = &stat;
    else
        stat_func = &lstat;

    //fstat = (t_stat*)ft_memalloc(sizeof(*fstat));
    while(*argv)
    {
        if (stat_func(*argv, &fstat) != 0)
        {
            printf("process_file(): stat: error\n");
            add_error(&error_lst, strerror(errno), *argv);
        }
        else if (!(S_ISDIR(fstat.st_mode)))
        {
            add_file(&file_lst, &fstat, NULL, *argv);
        }
        argv++;
    }
    print_error_lst(error_lst);
    print_file_lst(file_lst);
}
