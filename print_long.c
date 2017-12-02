/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:17:53 by asougako          #+#    #+#             */
/*   Updated: 2017/12/02 14:52:49 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define CONTENT		(t_xstat*)(*link).content
#define FILE_PATH	(*CONTENT).path
#define FILE_NAME	(*CONTENT).name
#define FILE_PRINT	(*CONTENT).printable
#define FILE_TYPE	(*(*CONTENT).stat).st_mode
#define FILE_BLOCKS	(*(*CONTENT).stat).st_blocks

#define STR_INODE	(*CONTENT).str_inode
#define STR_MODE	(*CONTENT).str_mode
#define STR_LINK	(*CONTENT).str_link
#define STR_USER	(*CONTENT).str_user
#define STR_GROUP	(*CONTENT).str_group
#define STR_MAJOR	(*CONTENT).str_major
#define STR_MINOR	(*CONTENT).str_minor
#define STR_SIZE	(*CONTENT).str_size
#define STR_DATE	(*CONTENT).str_date
#define STR_NAME	(*CONTENT).str_name
#define STR_SUFX	(*CONTENT).str_sufx
#define STR_XATTR	(*CONTENT).str_xattr
#define STR_ACL		(*CONTENT).str_acl


#define J_LEFT 0
#define J_RIGHT 1
void	print_col(char *field, uint16_t width, t_bool justify)
{
	uint16_t	index;
//	char		*tmp;
//	t_bool		is_number;

//	tmp = field;
//	is_number = true;
//	while (*tmp)
//	{
//		if (!ft_isdigit(*tmp))
//			is_number = false;
//		tmp++;
//	}
	if (justify == J_RIGHT)
	{
		index = ft_strlen(field);
		while (index < width)
		{
			ft_putchar(' ');
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
			ft_putchar(' ');
			index++;
		}
	}
	ft_putchar(' ');
}

char	*get_block_total(t_list *link)
{
	char		*ret;
	uint64_t	total;

	total = 0;
	while (link != NULL)
	{
		total += (*(*CONTENT).stat).st_blocks;
		link = (*link).next;
	}
	if (opt_k)
		total /= 2;
	ret = ft_itoa(total);
	return(ret);
}

#define  INODE_WIDTH (*colw).inode_w
#define  MODE_WIDTH (*colw).mode_w
#define  LINK_WIDTH (*colw).link_w
#define  USER_WIDTH (*colw).user_w
#define  GROUP_WIDTH (*colw).group_w
#define  MAJOR_WIDTH (*colw).major_w
#define  MINOR_WIDTH (*colw).minor_w
#define  SIZE_WIDTH (*colw).size_w
#define  DATE_WIDTH (*colw).date_w
void	print_file_lst_long(t_list *file_lst)
{
	t_list		*link;
	t_col_max_width	*colw;
	char *block_total;

	colw = (t_col_max_width*)ft_memalloc(sizeof(*colw));
	get_long_infos(file_lst, colw);
	link = file_lst;
	if (file_lst != NULL && FILE_PATH != NULL)
	{
		block_total = get_block_total(file_lst);
		ft_putstr("total ");
		ft_putendl(block_total);
		ft_strdel(&block_total);
	}
	while(link != NULL)
	{
		if (opt_i)
		{
			print_col(STR_INODE, INODE_WIDTH, J_RIGHT);
		}
		print_col(STR_MODE, 11, J_LEFT);
		print_col(STR_LINK, LINK_WIDTH, J_RIGHT);
		if (!(opt_g))
		{
			print_col(STR_USER, USER_WIDTH, J_LEFT);
			ft_putchar(0x20);
		}
		if (!(opt_o))
		{
			print_col(STR_GROUP, GROUP_WIDTH + 1, J_LEFT);
		}
		if (S_ISCHR(FILE_TYPE) || S_ISBLK(FILE_TYPE))
		{
			print_col(STR_MAJOR, 4, J_RIGHT);
			print_col(STR_MINOR, 3, J_RIGHT);
		}
		else
		{
			print_col(STR_SIZE, SIZE_WIDTH, J_RIGHT);
		}
		print_col(STR_DATE, DATE_WIDTH, J_LEFT);

		ft_putstr(STR_NAME);
		ft_putendl(STR_SUFX);

		//xattr
		if (opt_at)
			ft_putstr(STR_XATTR);

		//xattr
		if (opt_e)
			ft_putstr(STR_ACL);

		link = (*link).next;
	}
	ft_memdel((void**)&colw);
}

void	get_long_infos(t_list *head, t_col_max_width *colw)
{
	t_list 		*link;
	uint16_t	tmp;
	uint16_t	tmp2;

	link = head;
	while(link != NULL)
	{
		if (opt_i)
		{
			(*CONTENT).str_inode = get_inode(link);
			if ((tmp = ft_strlen((*CONTENT).str_inode)) > INODE_WIDTH)
				INODE_WIDTH = tmp;
		}
		(*CONTENT).str_mode = get_rights(link);
		(*CONTENT).str_link = get_links(link);
		if ((tmp = ft_strlen((*CONTENT).str_link)) > LINK_WIDTH)
			LINK_WIDTH = tmp;
		(*CONTENT).str_user = get_user(link);
		if ((tmp = ft_strlen((*CONTENT).str_user)) > USER_WIDTH)
			USER_WIDTH = tmp;
		(*CONTENT).str_group = get_group(link);
		if ((tmp = ft_strlen((*CONTENT).str_group)) > GROUP_WIDTH)
			GROUP_WIDTH = tmp;
		if (S_ISCHR(FILE_TYPE) || S_ISBLK(FILE_TYPE))
		{
			(*CONTENT).str_major = get_major(link);
			if ((tmp = ft_strlen((*CONTENT).str_major)) > MAJOR_WIDTH)
				MAJOR_WIDTH = tmp;
			(*CONTENT).str_minor = get_minor(link);
			if ((tmp2 = ft_strlen((*CONTENT).str_minor)) > MINOR_WIDTH)
				MINOR_WIDTH = tmp2;
			if ((tmp + tmp2 ) > SIZE_WIDTH)
				SIZE_WIDTH = 8;
		}
		else
		{
			(*CONTENT).str_size = get_size(link);
			if ((tmp = ft_strlen((*CONTENT).str_size)) > SIZE_WIDTH)
				SIZE_WIDTH = tmp;
			if (tmp > (MAJOR_WIDTH + MINOR_WIDTH))
				MAJOR_WIDTH = (tmp - MINOR_WIDTH) - 1;
		}
		(*CONTENT).str_date = get_date(link);
		if ((tmp = ft_strlen((*CONTENT).str_date)) > DATE_WIDTH)
			DATE_WIDTH = tmp;
		link = (*link).next;
	}
}
#undef  MODE_WIDTH
#undef  LINK_WIDTH
#undef  USER_WIDTH
#undef  GROUP_WIDTH
#undef  MAJOR_WIDTH
#undef  MINOR_WIDTH
#undef  SIZE_WIDTH
#undef  DATE_WIDTH

char	*get_rights(t_list *link)
{
	char *ret;

	ret = ft_strnew(11);
	*(ret + 0) = '-';
	S_ISFIFO(FILE_TYPE) ? *(ret + 0) = 'p' : 0;
	S_ISCHR(FILE_TYPE)  ? *(ret + 0) = 'c' : 0;
	S_ISDIR(FILE_TYPE)  ? *(ret + 0) = 'd' : 0;
	S_ISBLK(FILE_TYPE)  ? *(ret + 0) = 'b' : 0;
	S_ISREG(FILE_TYPE)  ? *(ret + 0) = '-' : 0;
	S_ISLNK(FILE_TYPE)  ? *(ret + 0) = 'l' : 0;
	S_ISSOCK(FILE_TYPE) ? *(ret + 0) = 's' : 0;

	*(ret + 1) = FILE_TYPE & S_IRUSR ? 'r' : '-';
	*(ret + 2) = FILE_TYPE & S_IWUSR ? 'w' : '-';
	if ((FILE_TYPE & S_IXUSR) && (FILE_TYPE & S_ISUID))
		*(ret + 3) = 's';
	else if (FILE_TYPE & S_ISUID)
		*(ret + 3) = 'S';
	else if (FILE_TYPE & S_IXUSR)
		*(ret + 3) = 'x';
	else
		*(ret + 3) = '-';

	*(ret + 4) = FILE_TYPE & S_IRGRP ? 'r' : '-';
	*(ret + 5) = FILE_TYPE & S_IWGRP ? 'w' : '-';
	if ((FILE_TYPE & S_IXGRP) && (FILE_TYPE & S_ISGID))
		*(ret + 6) = 's';
	else if (FILE_TYPE & S_ISGID)
		*(ret + 6) = 'S';
	else if (FILE_TYPE & S_IXGRP)
		*(ret + 6) = 'x';
	else
		*(ret + 6) = '-';

	*(ret + 7) = FILE_TYPE & S_IROTH ? 'r' : '-';
	*(ret + 8) = FILE_TYPE & S_IWOTH ? 'w' : '-';

	if ((FILE_TYPE & S_IXOTH) && (FILE_TYPE & S_ISVTX))
		*(ret + 9) = 't';
	else if(FILE_TYPE & S_ISVTX)
		*(ret + 9) = 'T';
	else if (FILE_TYPE & S_IXOTH)
		*(ret + 9) = 'x';
	else
		*(ret + 9) = '-';

	if (STR_ACL)
		*(ret + 10) = '+';
	else if(STR_XATTR)
		*(ret + 10) = '@';
	return(ret);
}

char	*get_inode(t_list *link)
{
	return (ft_itoa((*(*CONTENT).stat).st_ino));
}

char	*get_links(t_list *link)
{
	return (ft_itoa((*(*CONTENT).stat).st_nlink));
}

char	*get_user(t_list *link)
{
	char			*ret;
	struct passwd	*passwd;

	ret = NULL;
	passwd = NULL;
	if (opt_n)
	{
		ret = ft_itoa((*(*CONTENT).stat).st_uid);
	}
	else
	{
		if ((passwd = getpwuid((*(*CONTENT).stat).st_uid)) == 0)
			ret = ft_itoa((*(*CONTENT).stat).st_uid);
		else
			ret = ft_strdup((*passwd).pw_name);
	}
	return(ret);
}

char	*get_group(t_list *link)
{
	char	*ret;
	struct group *group;


	ret = NULL;
	group = NULL;
	if (opt_n)
	{
		ret = ft_itoa((*(*CONTENT).stat).st_gid);
	}
	else
	{
		if ((group = getgrgid((*(*CONTENT).stat).st_gid)) == 0)
			ret = ft_itoa((*(*CONTENT).stat).st_gid);
		else
			ret = ft_strdup((*group).gr_name);
	}
	return(ret);
}

char	*get_major(t_list *link)
{
	char	*ret;
	char	*to_free;

	to_free = ft_itoa(major((*(*CONTENT).stat).st_rdev));
	ret = ft_strjoin(to_free, ",");
	ft_memdel((void **)&to_free);
	return (ret);
}

char	*get_minor(t_list *link)
{
	return (ft_itoa(minor((*(*CONTENT).stat).st_rdev)));
}

char	*get_size(t_list *link)
{
	return (ft_itoa((*(*CONTENT).stat).st_size));
}

#define SIX_MONTHS 15552000
#define FILE_ATIME (*(*CONTENT).stat).st_atime
#define FILE_BTIME (*(*CONTENT).stat).st_birthtime
#define FILE_CTIME (*(*CONTENT).stat).st_ctime
#define FILE_MTIME (*(*CONTENT).stat).st_mtime
char	*get_date(t_list *link)
{
	char	*ret;
	char	*tmp;
	time_t	now;
	time_t	file_time;

	if (opt_l && opt_u)
		file_time = (*(*CONTENT).stat).st_atime;
	else if (opt_l && opt_U)
		file_time = (*(*CONTENT).stat).st_birthtime;
	else if (opt_l && opt_c)
		file_time = (*(*CONTENT).stat).st_ctime;
	else
		file_time = (*(*CONTENT).stat).st_mtime;

	now = time(NULL);
	ret = ft_strnew(21);
	tmp = ft_strdup(ctime(&file_time));

	ft_strncpy(ret, tmp + 4, 7);
	if (opt_T)
	{
		ft_strncpy(ret + 7, tmp + 11, 13);
	}
	else if (file_time > now || file_time  < now - SIX_MONTHS)
	{
		if (*(tmp + 20) == 0x20)
			ft_strncpy(ret + 7, tmp + 24, 5);
		else
			ft_strncpy(ret + 7, tmp + 19, 5);
	}
	else
	{
		ft_strncpy(ret + 7, tmp + 11, 5);
	}
	ft_memdel((void**)&tmp);
	return(ret);
}

#undef CONTENT
#undef FILE_NAME
#undef FILE_PRINT
#undef HAS_XATTR
#undef FILE_TYPE
#undef FILE_MODE
#undef FILE_LINK
#undef FILE_USER
#undef FILE_GROUP
#undef FILE_MAJOR
#undef FILE_MINOR
#undef FILE_SIZE
#undef FILE_DATE
