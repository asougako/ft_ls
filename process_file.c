
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
	ft_strdel(&error);
}

static void	get_xattr(t_list *file_link, char *path)
{
	if (OPT(L))
		FILE_XASIZE = listxattr(path, NULL, 0);
	//FILE_XASIZE = listxattr(path, NULL, 0, 0);
	else
		FILE_XASIZE = listxattr(path, NULL, 0);
	//FILE_XASIZE = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (FILE_XASIZE < 0)
	{
		FILE_XATTR = NULL;
		return;
	}
	if (FILE_XASIZE == 0)
		return;
	FILE_XATTR = ft_strnew(FILE_XASIZE);
	if (OPT(L))
		FILE_XASIZE = listxattr(path, FILE_XATTR, FILE_XASIZE);
	//FILE_XASIZE = listxattr(path, FILE_XATTR, FILE_XASIZE, 0);
	else
		FILE_XASIZE = listxattr(path, FILE_XATTR, FILE_XASIZE);
	//FILE_XASIZE = listxattr(path, FILE_XATTR, FILE_XASIZE, XATTR_NOFOLLOW);
	if (FILE_XASIZE < 0)
	{
		FILE_XATTR = NULL;
		return;
	}
}

#ifndef linux
static void	get_acl(t_list	*file_link, char * path)
{
	acl_t	acl;
	acl_entry_t	*entry;
	int		errnum;

	//get acl
	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) == NULL)
	{
		//	errnum = errno;
		// 	printf("%s: %s(%d)\n", path, strerror(errnum), errnum);
		return;
	}

	entry = ft_memalloc(sizeof(*entry));
	if ((acl_get_entry(acl, ACL_FIRST_ENTRY, entry)) == -1)
	{
		errnum = errno;
		//printf("%s: %s(%d)\n", path, strerror(errnum), errnum);
		return;
	}
	ft_putendl("");
	ft_print_memory(entry, sizeof(*entry));
}
#else

#endif

char *get_referred_link(char *dir, char *file)
{
	char	*path;
	char	*buff;
	char	*ret;
	size_t	index;
	size_t	file_len;

	index = 0;
	file_len = 0;
	path = path_join(dir, file);
	file_len = ft_strlen(file);
	buff = ft_strnew(file_len + 4 + PATH_MAX + 1);
	ft_strcpy(buff + index, file);
	index += file_len;
	ft_strcpy(buff + index, " -> ");
	index += 4;
	if (readlink(path, buff + index, PATH_MAX) < 0)
		ret = ft_strdup(file);
	else
		ret = ft_strdup(buff);
	ft_strdel(&path);
	ft_strdel(&buff);
	return(ret);
}

void    add_file(t_list **file_lst, t_stat *fstat, char *dir, char *file)
{
	t_list	*file_link;
	t_xstat	*xfs;
	char	*path;

	xfs = NULL;
	xfs = (t_xstat*)ft_memalloc(sizeof(*xfs));

	if ((file_link = ft_lstnew(NULL, sizeof(t_xstat*))) == NULL)
		print_error_malloc(errno);
	(*file_link).content = xfs;

	if (OPT(l) && S_ISLNK((*fstat).st_mode))	//NULL fstat protect?
		FILE_NAME = get_referred_link(dir, file);
	else
		FILE_NAME = ft_strdup(file);


	if (dir != NULL)
		FILE_PATH = ft_strdup(dir);

	if (fstat != NULL)
		FILE_STAT = (t_stat*)ft_memdup(fstat, sizeof(*fstat));

	if (OPT(l))
	{
		if (dir == NULL)
		{
			get_xattr(file_link, file);
#ifndef linux
			get_acl(file_link, file);
#endif
		}
		else
		{
			path = path_join(dir, file);
			get_xattr(file_link, path);
#ifndef linux
			get_acl(file_link, path);
#endif
			ft_strdel(&path);
		}
	}

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

	if (OPT(L) || OPT(H))
		stat_func = &stat;
	else
		stat_func = &lstat;

	while(*argv)
	{
		if (stat_func(*argv, &fstat) != 0)
		{
			add_error(&error_lst, strerror(errno), *argv);
		}
		else if (!(S_ISDIR(fstat.st_mode)) || (OPT(d)))
		{
			add_file(&file_lst, &fstat, NULL, *argv);
		}
		argv++;
	}
	print_error_lst(error_lst);
	if (file_lst != NULL)
		print_file_lst(file_lst);
	ft_lstdel(&error_lst, errlst_destructor);
	ft_lstdel(&file_lst, lst_destructor);
}
