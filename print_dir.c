
#include "ft_ls.h"

#define content (t_file_infos*)(*link).content

#define file_name (*content).name
//#define file_name (*(*content).dir).d_name
#define file_type (*(*content).dir).d_type
#define file_print  (*content).printable

#define HAS_XATTR (*content).has_xattr
#define FILE_MODE (*(*content).stat).st_mode

#define file_mode   (*content).mode
#define file_link   (*content).link
#define file_user	(*content).user
#define file_group	(*content).group
#define file_major	(*content).major
#define file_minor	(*content).minor
#define file_size	(*content).size
#define file_date	(*content).date

void    print_dir(t_list *head)
{
		if ((opt & opt_l) != 0)
				print_dir_long(head);
		else
				print_dir_short(head);
}

void	print_col(char *field, uint16_t width)
{
		uint16_t		index;

		if (ft_isdigit(*field))
		{
				index = ft_strlen(field);
				while (index < width)
				{
						ft_putchar(0x20);
						index++;
				}
				ft_putstr(field);
		}
		else
		{
				ft_putstr(field);
				index = ft_strlen(field);
				while (index < (width))
				{
						ft_putchar(0x20);
						index++;
				}
		}
		ft_putchar(0x20);
}

#define  MODE_WIDTH (*colw).mode_w
#define  LINK_WIDTH (*colw).link_w
#define  USER_WIDTH (*colw).user_w
#define  GROUP_WIDTH (*colw).group_w
#define  MAJOR_WIDTH (*colw).major_w
#define  MINOR_WIDTH (*colw).minor_w
#define  SIZE_WIDTH (*colw).size_w
#define  DATE_WIDTH (*colw).date_w
void	print_dir_long(t_list *head)
{
		t_list			*link;
		t_max_col_width	*colw;

		colw = (t_max_col_width*)ft_memalloc(sizeof(*colw));
		get_long_infos(head, colw);
		link = head;
		while(link != NULL)
		{
				if (file_print == true)
				{
						print_col(file_mode, MODE_WIDTH);
						print_col(file_link, LINK_WIDTH);
						print_col(file_user, USER_WIDTH);
						print_col(file_group, GROUP_WIDTH);
						if (S_ISCHR(FILE_MODE) || S_ISBLK(FILE_MODE))
						{
								print_col(file_major, MAJOR_WIDTH);
								print_col(file_minor, MINOR_WIDTH);
						}
						else
						{
								print_col(file_size, SIZE_WIDTH);
						}
						print_col(file_date, DATE_WIDTH);

						ft_putendl(file_name);
				}
				link = (*link).next;
		}
}

void	get_long_infos(t_list *head, t_max_col_width *colw)
{
		t_list 		*link;
		uint16_t	max_width;
		uint16_t	tmp;
		uint16_t	tmp2;

		link = head;
		while(link != NULL)
		{
				(*content).mode = get_rights(link);
				if ((tmp = ft_strlen((*content).mode)) > MODE_WIDTH)
						MODE_WIDTH = tmp;

				(*content).link = get_links(link);
				if ((tmp = ft_strlen((*content).link)) > LINK_WIDTH)
						LINK_WIDTH = tmp;

				(*content).user = get_user(link);
				if ((tmp = ft_strlen((*content).user)) > USER_WIDTH)
						USER_WIDTH = tmp;

				(*content).group = get_group(link);
				if ((tmp = ft_strlen((*content).group)) > GROUP_WIDTH)
						GROUP_WIDTH = tmp;

				if (S_ISCHR(FILE_MODE) || S_ISBLK(FILE_MODE))
				{
						(*content).major = get_major(link);
						if ((tmp = ft_strlen((*content).major)) > MAJOR_WIDTH)
								MAJOR_WIDTH = tmp;
						(*content).minor = get_minor(link);
						if ((tmp2 = ft_strlen((*content).minor)) > MINOR_WIDTH)
								MINOR_WIDTH = tmp2;
						if ((tmp + tmp2 ) > SIZE_WIDTH)
								SIZE_WIDTH = tmp + tmp2;
				}
				else
				{
						(*content).size = get_size(link);
						if ((tmp = ft_strlen((*content).size)) > SIZE_WIDTH)
								SIZE_WIDTH = tmp;
						if (tmp > (MAJOR_WIDTH + MINOR_WIDTH))
								MAJOR_WIDTH = (tmp - MINOR_WIDTH) - 1;
				}

				(*content).date = get_date(link);
				if ((tmp = ft_strlen((*content).date)) > DATE_WIDTH)
						DATE_WIDTH = tmp;
				link = (*link).next;
		}
}

char	*get_rights(t_list *link)
{
		char *ret;

		ret = ft_strnew(11);
		S_ISDIR(FILE_MODE)  ? *(ret + 0) = 'd' : 0;
		S_ISREG(FILE_MODE)  ? *(ret + 0) = '-' : 0;
		S_ISLNK(FILE_MODE)  ? *(ret + 0) = 'l' : 0;
		S_ISCHR(FILE_MODE)  ? *(ret + 0) = 'c' : 0;
		S_ISBLK(FILE_MODE)  ? *(ret + 0) = 'b' : 0;
		S_ISFIFO(FILE_MODE) ? *(ret + 0) = 'p' : 0;
		*(ret + 1) = FILE_MODE & S_IRUSR ? 'r' : '-';
		*(ret + 2) = FILE_MODE & S_IWUSR ? 'w' : '-';
		*(ret + 3) = FILE_MODE & S_IXUSR ? 'x' : '-';
		*(ret + 4) = FILE_MODE & S_IRGRP ? 'r' : '-';
		*(ret + 5) = FILE_MODE & S_IWGRP ? 'w' : '-';
		*(ret + 6) = FILE_MODE & S_IXGRP ? 'x' : '-';
		*(ret + 7) = FILE_MODE & S_IROTH ? 'r' : '-';
		*(ret + 8) = FILE_MODE & S_IWOTH ? 'w' : '-';
		*(ret + 9) = FILE_MODE & S_IXOTH ? 'x' : '-';
		*(ret + 10) = HAS_XATTR ? '+' : '\0';

		return(ret);
}

char	*get_links(t_list *link)
{
		return (ft_itoa((*(*content).stat).st_nlink));
}

char	*get_user(t_list *link)
{
		char			*ret;
		struct passwd	*passwd;

		ret = NULL;
		passwd = NULL;
		if (opt & opt_n)
				ret = ft_strdup(ft_itoa((*(*content).stat).st_uid));
		else
		{
				passwd = getpwuid((*(*content).stat).st_uid);
				ret = ft_strdup((*passwd).pw_name);
		}
		return(ret);
}

char	*get_group(t_list *link)
{
		char	*ret;
		struct group *group = NULL;

		if (opt & opt_n)
		{
				ret = ft_strdup(ft_itoa((*(*content).stat).st_gid));
		}
		else
		{
				group = getgrgid((*(*content).stat).st_gid);
				ret = ft_strdup((*group).gr_name);
		}
		return(ret);
}

char	*get_major(t_list *link)
{
		char	*ret;
		char	*to_free;

		to_free = ft_itoa(major((*(*content).stat).st_rdev));
		ret = ft_strjoin(to_free, ",");
		ft_memdel((void **)&to_free);
		return (ret);
}

char	*get_minor(t_list *link)
{
		return (ft_itoa(minor((*(*content).stat).st_rdev)));
}

char	*get_size(t_list *link)
{
		return (ft_itoa((*(*content).stat).st_size));
}

char	*get_date(t_list *link)
{
		char	*ret;
		char	*cut;
		time_t	time;

		if (opt & opt_l && opt & opt_u)
				time = (*(*content).stat).st_atime;
		else if (opt & opt_l && opt & opt_c)
				time = (*(*content).stat).st_ctime;
		else
				time = (*(*content).stat).st_mtime;

		ret = ft_strdup(ctime(&time));
		ret = ft_strchr(ret, 0x20);
		ret++;
		cut = ft_strchr(ret, ':');
		cut = ft_strchr(cut + 1, ':');
		*cut = '\0';
		return(ret);
}

#undef content
#undef file_name
#undef file_type
#undef file_print

