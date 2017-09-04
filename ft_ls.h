#ifndef FT_LS_H
#define FT_LS_H

//INCLUDES//
#include <sys/sysmacros.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>  //perror
#include <errno.h>
#include "libft/libft.h"
#include "options/ft_options.h"
#include "ft_ls.h"

#include <time.h>

#define pf(VAR, TYPE) printf(#VAR" = %"#TYPE"\n", VAR)



//TYPEDEFS//
typedef enum e_bool
{
		false,
		true
}						bool;

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct s_file_infos
{
		t_dirent	*dir;
		t_stat		*stat;
		bool		has_xattr;
		bool		printable;
		char		*name;
		size_t		name_len;
		char		*mode;
		char		*link;
		char		*user;
		char		*group;
		char		*major;
		char		*minor;
		char		*size;
		char		*date;
}						t_file_infos;

typedef struct		s_tab_format
{
		uint32_t    tab_len;
		uint32_t    columns;
		uint32_t    lines;
		uint32_t	*col_width;
}					t_tab_format;

typedef struct		s_max_col_width
{
		uint16_t	mode_w;
		uint16_t	link_w;
		uint16_t	user_w;
		uint16_t	group_w;
		uint16_t	major_w;
		uint16_t	minor_w;
		uint16_t	size_w;
		uint16_t	date_w;
}					t_max_col_width;

//GLOBALS//
uint64_t	opt;
t_list		*long_opt;
char		*prog_name;


//FUNCTIONS//
void	test(void);
//sort
int		ft_lstsort(t_list **head, t_list *link);
int		name_sort(void *content1, void *content2);
int		size_sort(void *content1, void *content2);
int		atime_sort(void *content1, void *content2);
int		ctime_sort(void *content1, void *content2);
int		mtime_sort(void *content1, void *content2);
int		rev_name_sort(void *content1, void *content2);
int		rev_size_sort(void *content1, void *content2);
int		rev_atime_sort(void *content1, void *content2);
int		rev_ctime_sort(void *content1, void *content2);
int		rev_mtime_sort(void *content1, void *content2);
int		no_sort(void *content1, void *content2);

//print
void	print_error_access(char *err, char *path);
void    print_malloc_error(void);
void	print_dir(t_list *head);
void    print_dir_short(t_list *head);
void    print_dir_long(t_list *head);
void	print_help(void);
char	*get_rights(t_list *link);
char	*get_links(t_list *link);
char	*get_user(t_list *link);
char	*get_group(t_list *link);
char	*get_major(t_list *link);
char	*get_minor(t_list *link);
char	*get_size(t_list *link);
char	*get_date(t_list *link);
void	get_long_infos(t_list *head, t_max_col_width *colw);

//process
int		process_dir(char *path);
int     process_file(char *file_path);
t_list	*lst_cur_dir(DIR *dir_stream, char *directory);
t_stat	*get_file_stat(char *directory, char *file);
void	lst_destruct(void *cont, size_t size);
void	recursive(t_list *l_dir_info, char *path);

//opt
void    process_opt(t_list *l_dir_infos);
void    process_opt_a(t_list *l_dir_info);
void    process_opt_A(t_list *l_dir_info);
void    process_opt_B(t_list *l_dir_info);

#endif
