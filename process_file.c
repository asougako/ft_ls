
#include "ft_ls.h"

#define FILE_STAT (*(t_xstat*)(*file_link).content).stat
#define FILE_TYPE (*(*(t_xstat*)(*file_link).content).stat).st_mode
#define FILE_PATH (*(t_xstat*)(*file_link).content).path
#define FILE_NAME (*(t_xstat*)(*file_link).content).name
#define FILE_LINK (*(t_xstat*)(*file_link).content).link
#define FILE_ERROR (*(t_xstat*)(*file_link).content).file_error

#define STR_NAME	(*(t_xstat*)(*file_link).content).str_name
#define STR_SUFX	(*(t_xstat*)(*file_link).content).str_sufx
#define STR_XATTR	(*(t_xstat*)(*file_link).content).str_xattr
void	add_error(t_list **error_lst, char *err, char *file)
{
	char        *error;
	t_list      *error_link;

	error = str_error_access(err, file);
	if ((error_link = ft_lstnew(error, ft_strlen(error))) == NULL)
		print_error_malloc(errno);

	if (opt_r)
		ft_lstadd(error_lst, error_link);
	else
		ft_lstadd_tail(error_lst, error_link);

	ft_strdel(&error);
}

char *format_str_xattr(char *attr, int size)
{
	int len;
	char *ret;
	char *del;

	len = ft_strlen(attr);
	ret = ft_strnew(len + 7);
	*(ret + 0) = '\t';
	ft_strcpy(ret + 1, attr);
	*(ret + len + 1) = '\t';
	*(ret + len + 2) = ' ';
	*(ret + len + 3) = ' ';
	*(ret + len + 4) = ' ';
	*(ret + len + 5) = ' ';
	del = ft_itoa(size);
	ft_strcpy(ret + len + 6 - ft_strlen(del), del);
	ft_strdel(&del);
	*(ret + len + 6) = '\n';
	return(ret);
}

static void	get_xattr(t_list *file_link)
{
	int		size;
	int		index;
	char	*del1;
	char	*del2;
	char	*buff;
	char	*path;
	char	*str_xa;

	str_xa = ft_strdup("");;
	path = path_join(FILE_PATH, FILE_NAME);
	if ((size = listxattr(path, NULL, 0, XATTR_NOFOLLOW)) <= 0)
	{
		ft_strdel(&str_xa);
		ft_strdel(&path);
		return;
	}
	buff = ft_strnew(size);
	listxattr(path, buff, size, XATTR_NOFOLLOW);
	size = 0;
	index = 0;
	while ((size = getxattr(path, buff + index, NULL, 0, 0, XATTR_NOFOLLOW)) >= 0)
	{
		del1 = str_xa;
		del2 = format_str_xattr(buff, size);
		str_xa = ft_strjoin(str_xa, del2);
		ft_strdel(&del1);
		ft_strdel(&del2);
		index += (ft_strlen(buff + index) + 1);
	}
	STR_XATTR = str_xa;
	//	ft_strdel(&str_xa);
	ft_strdel(&path);
	ft_strdel(&buff);
}

static void	get_acl(t_list	*file_link, char * path)
{
	acl_t		acl;
	//	acl_entry_t	*entry;
	//	int			errnum;
	ssize_t		*len_p;


	//get acl
	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) == NULL)
	{
		//			errnum = errno;
		//		 	printf("%s: %s(%d)\n", path, strerror(errnum), errnum);
		return;
	}

	//	entry = ft_memalloc(sizeof(*entry));
	//	if ((acl_get_entry(acl, ACL_FIRST_ENTRY, entry)) == -1)
	//	{
	//		errnum = errno;
	//		printf("%s: %s(%d)\n", path, strerror(errnum), errnum);
	//		return;
	//	}

	//	printf("ACL:%s\n", (*(t_xstat*)(*file_link).content).name);
	len_p = NULL;
	len_p = (ssize_t*)ft_memalloc(sizeof(*len_p));
	(*(t_xstat*)(*file_link).content).str_acl = acl_to_text(acl, len_p);

	//ft_memdel((void**)&entry);
}


char *get_referred_link(t_list *file_link)
{
	char	*path;
	char	*buff;
	char	*ret;
	size_t	index;
	size_t	file_len;

	index = 0;
	file_len = 0;

	path = path_join(FILE_PATH, FILE_NAME);
	buff = ft_strnew( 4 + PATH_MAX + 1);
	ft_strcpy(buff + index, " -> ");
	index += 4;
	if (readlink(path, buff + index, PATH_MAX) < 0)
	{
		ret = NULL;
	}
	else
	{
		ret = ft_strdup(buff);
	}
	ft_strdel(&path);
	ft_strdel(&buff);
	return(ret);
}

char	*get_type(mode_t mode)
{
	if (S_ISDIR(mode))
		return(ft_strdup("/"));
	if (S_ISLNK(mode))
		return(ft_strdup("@"));
	if (S_ISSOCK(mode))
		return(ft_strdup("="));
	if (S_ISWHT(mode))
		return(ft_strdup("%"));
	if (S_ISFIFO(mode))
		return(ft_strdup("|"));
	if (mode & 00111)
		return(ft_strdup("*"));
	return(NULL);
}

void	get_suffixe(t_list *file_link)
{
	int		index;
	char	*type;
	char	*reflnk;

	index = 0;
	type = NULL;
	reflnk = NULL;
	if (opt_F || (opt_p && S_ISDIR(FILE_TYPE)))
	{
		type = get_type(FILE_TYPE);
		index++;
	}
	if (opt_l && S_ISLNK((*FILE_STAT).st_mode))
	{
		reflnk = get_referred_link(file_link);
		index += ft_strlen(reflnk);
	}
	STR_SUFX = ft_strnew(index);
	index = 0;
	if (type != NULL)
	{
//		STR_SUFX = ft_strcpy(STR_SUFX, type);
		STR_NAME = ft_strjoin(STR_NAME, type);
		index++;
	}
	if (reflnk != NULL)
	{
		ft_strcpy(STR_SUFX + 0, reflnk);
	}
	ft_strdel(&type);
	ft_strdel(&reflnk);
}

#define C_NORMAL		"\e[0m"
#define C_RED			"\e[0;31m"
#define C_GREEN			"\e[0;32m"
#define C_YELLOW		"\e[0;33m"
#define C_PURPLE		"\e[0;35m"
#define C_CYAN			"\e[1;36m"
#define C_BLUE_YELLOW	"\e[43;34m"
#define C_BLUE_CYAN		"\e[46;34m"
#define C_BACK_RED		"\e[41;30m"
#define C_BACK_CYAN		"\e[46;30m"
#define C_BLACK_GREEN	"\e[42;30m"
#define C_BLACK_YELLOW	"\e[43;30m"

char	*color_name(t_list	*file_link, char *name)
{
	char *ret;
	char *color;
	int		name_len;
	int		color_len;

	if (!(opt_G))
		return(ft_strdup(name));

	if (S_ISDIR(FILE_TYPE) && (FILE_TYPE & S_IWOTH) && (FILE_TYPE & S_ISVTX))
		color = ft_strdup(C_BLACK_GREEN);
	else if (S_ISFIFO(FILE_TYPE))	//p
		color = ft_strdup(C_YELLOW);
	else if (S_ISSOCK(FILE_TYPE))	//s
		color = ft_strdup(C_GREEN);
	else if (S_ISDIR(FILE_TYPE) && (FILE_TYPE & S_IWOTH))	//d
		color = ft_strdup(C_BLACK_YELLOW);
	else if (S_ISDIR(FILE_TYPE))	//d
		color = ft_strdup(C_CYAN);
	else if (S_ISBLK(FILE_TYPE))	//b
		color = ft_strdup(C_BLUE_CYAN);
	else if (S_ISCHR(FILE_TYPE))	//c
		color = ft_strdup(C_BLUE_YELLOW);
	else if (S_ISLNK(FILE_TYPE))	//l
		color = ft_strdup(C_PURPLE);

	else if ((FILE_TYPE & S_ISUID) && (FILE_TYPE & S_IXUSR))
		color = ft_strdup(C_BACK_RED);
	else if ((FILE_TYPE & S_ISGID) && (FILE_TYPE & S_IXGRP))
		color = ft_strdup(C_BACK_CYAN);
	else if (FILE_TYPE & 00111)
		color = ft_strdup(C_RED);
	else
		return(ft_strdup(name));

	color_len = ft_strlen(color);
	name_len = ft_strlen(name);

	ret = ft_strnew(ft_strlen(color) + ft_strlen(name) + 4);
	ft_strcpy(ret, color);
	ft_strcpy(ret + color_len, name);
	ft_strcpy(ret + color_len + ft_strlen(name), C_NORMAL);
	ft_strdel(&color);
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

	FILE_NAME = ft_strdup(file);
	//PATH
	if (dir != NULL)
		FILE_PATH = ft_strdup(dir);
	//STAT
	if (fstat != NULL)
		FILE_STAT = (t_stat*)ft_memdup(fstat, sizeof(*fstat));
	//NAME
	//STR_NAME = ft_strdup(file);
	STR_NAME = color_name(file_link, file);

	get_suffixe(file_link);
	if (opt_l)
	{
		if (dir == NULL)
		{
			get_xattr(file_link);
			get_acl(file_link, file);
		}
		else
		{
			path = path_join(dir, file);
			get_xattr(file_link);
			get_acl(file_link, path);
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

int		process_files(char **argv)
{
	t_stat      fstat;
	t_list      *file_lst;
	t_list      *error_lst;
	int         (*stat_func)(const char *restrict, struct stat *restrict);
	int			index;

	index = 0;
	file_lst = NULL;
	error_lst = NULL;

	if (opt_L || opt_H)
		stat_func = &stat;
	else
		stat_func = &lstat;

	while(*argv)
	{
		if (stat_func(*argv, &fstat) != 0)
		{
			add_error(&error_lst, strerror(errno), *argv);
		}
		else if (!(S_ISDIR(fstat.st_mode)) || (opt_d))
		{
			add_file(&file_lst, &fstat, NULL, *argv);
			index++;
		}
		argv++;
	}
	print_error_lst(error_lst);
	if (file_lst != NULL)
		print_file_lst(file_lst);
	ft_lstdel(&error_lst, errlst_destructor);
	ft_lstdel(&file_lst, lst_destructor);
	return(index);
}
