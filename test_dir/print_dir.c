
#include "ft_ls.h"

#define content (t_file_infos*)(*link).content
#define file_name (*(*content).dir).d_name
#define file_type (*(*content).dir).d_type
#define file_print  (*content).printable

#define d_malloc(TYPE, VAR, SIZE)\
		do {if ((VAR = (TYPE)ft_memalloc(SIZE * sizeof(*VAR))) == NULL)\
				printf("malloc error!\n");\
		} while(0)

void    print_dir(t_list *head)
{
		if ((opt & opt_l) != 0)
				print_dir_long(head);
		else
				print_dir_short(head);
}

t_file_infos	**tab_names(t_list *head)
{
		int				index;
		t_list			*link;
		t_file_infos	**names;

		link = head;
		index = 0;
		while(link != NULL)
		{
				if (file_print == true)
				{
						index++;
				}
				link = (*link).next;
		}

		d_malloc(t_file_infos**, names, index + 1);

		link = head;
		index = 0;
		while(link != NULL)
		{
				if (file_print == true)
				{
						*(names + index) = content;
				}
				link = (*link).next;
				index++;
		}
		return(names);
}

struct	s_format
{
		uint32_t	tab_len;
		uint32_t	columns;
		uint32_t	lines;
};

uint32_t	print_len(uint32_t cols, t_file_infos **names)
{
		uint32_t	len;
		uint32_t	lines;

		lines = (((tab_len - 1) / columns) + 1);


		return(len)
}

uint32_t	how_much_cols(t_file_infos **names)
{
		struct		winsize w;
		uint32_t	cols;
		uint32_t	namespercol;

		//term_size
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		printf("term_size = %d x %d\n", w.ws_row, w.ws_col);

		cols = 1;
		while (print_len(cols, names) < w.ws_col)
		{
				cols++;
		}
		return(cols);
}

#define pf(VAR, TYPE) printf(#VAR" = %"#TYPE"\n", VAR)
#define tab_file_name (*(*(*(names + index + (col_index * (namespercol))))).dir).d_name
void	print_dir_short(t_list *head)
{
		t_file_infos	**names;
		uint32_t		columns;
		uint32_t		index;
		uint32_t		col_index;
		uint32_t		tab_len;
		uint32_t		namespercol;


		//tab of names
		names = tab_names(head);

		tab_len = ft_strtab_len((char **)names);
		columns = how_much_cols(names);
		namespercol = (((tab_len - 1) / columns) + 1);

		pf(tab_len, d);
		pf(columns, d);
		pf(namespercol, d);

		ft_putendl("");
		index = 0;
		while (index < namespercol)
		{
				col_index = 0;
				while (col_index < columns)
				{
						if ((*(names + index + (col_index * (namespercol)))) == NULL)
						{
								break;
						}

						ft_putstr(tab_file_name );
						ft_putchar('\t');
						col_index++;
				}
				ft_putendl("");
				index++;
		}

/*
		link = head;
		while(link != NULL)
		{
				if (file_print == true)
				{
						ft_putendl(file_name);
						printf("size = %d\n", (*content).name_len);
				}
				link = (*link).next;
		}
*/
}

void	print_dir_long(t_list *head)
{
		t_list  *link;

		link = head;
		while(link != NULL)
		{
				if (file_print == true)
				{
						print_rights((*(*content).stat).st_mode);
						ft_putendl(file_name);
				}
				link = (*link).next;
		}
}

void	stat_to_str(t_list *link)
{
		while(link != NULL)
		{
				link = (*link).next;
		}
}

void	print_rights(mode_t mode)
{
		char *ret;
		char *xa;

		S_ISDIR(mode)  ? ft_putchar('d'): 0;
		S_ISREG(mode)  ? ft_putchar('-'): 0;
		S_ISLNK(mode)  ? ft_putchar('l'): 0;
		S_ISCHR(mode)  ? ft_putchar('c'): 0;
		S_ISBLK(mode)  ? ft_putchar('b'): 0;
		S_ISFIFO(mode) ? ft_putchar('p'): 0;
		mode & S_IRUSR ? ft_putchar('r'): ft_putchar('-');
		mode & S_IWUSR ? ft_putchar('w'): ft_putchar('-');
		mode & S_IXUSR ? ft_putchar('x'): ft_putchar('-');
		mode & S_IRGRP ? ft_putchar('r'): ft_putchar('-');
		mode & S_IWGRP ? ft_putchar('w'): ft_putchar('-');
		mode & S_IXGRP ? ft_putchar('x'): ft_putchar('-');
		mode & S_IROTH ? ft_putchar('r'): ft_putchar('-');
		mode & S_IWOTH ? ft_putchar('w'): ft_putchar('-');
		mode & S_IXOTH ? ft_putchar('x'): ft_putchar('-');
		//listxattr(path, xa, 666) >= 0 ? ft_putchar('+') : 0;
		ft_putchar(0x20);
}

#undef content
#undef file_name
#undef file_type
#undef file_print

