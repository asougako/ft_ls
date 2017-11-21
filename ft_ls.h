#ifndef FT_LS_H
#define FT_LS_H

//INCLUDES//
#ifdef linux
#include <sys/sysmacros.h>
#endif
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>  //perror
#include <errno.h>
#include "parsing/ft_getopt.h"
#include "libft/libft.h"
#include "ft_ls.h"

#include <time.h>

#define pf(VAR, TYPE) printf(#VAR" = %"#TYPE"\n", VAR)
#define flag(CHAR) sopt(NULL).opt & opt_##CHAR
#define OPT(OPTION)  sopt(NULL).opt & opt_##OPTION
#define NORESET 0
#define RESET 1
#define LOOP_ERROR 1
//TYPEDEFS//
typedef enum e_bool
{
		false,
		true = !false
}						bool;

typedef struct		dirent t_dirent;
typedef struct		stat t_stat;

typedef struct		s_xstat
{
	//Raw
//	bool		printable;
	t_stat		*stat;
	char		*path;
	char		*name;		//if NULL? not printable
	char		*xattr;		//if NULL? no xattr
	int		xa_size;
	char		*error;	//if NULL? no error
//	unsigned char	type;
//	size_t		name_len;
//	bool		has_xattr;
//	bool		has_error;

	//Stringified
	char		*str_inode;
	char		*str_mode;
	char		*str_link;
	char		*str_user;
	char		*str_group;
	char		*str_major;
	char		*str_minor;
	char		*str_size;
	char		*str_date;
}			t_xstat;

typedef struct		s_tab_format
{
	uint32_t	tab_len;
	uint32_t	columns;
	uint32_t	lines;
	uint32_t	*col_width;
}					t_tab_format;

typedef struct			s_col_max_width
{
	uint16_t	inode_w;
	uint16_t	mode_w;
	uint16_t	link_w;
	uint16_t	user_w;
	uint16_t	group_w;
	uint16_t	major_w;
	uint16_t	minor_w;
	uint16_t	size_w;
	uint16_t	date_w;
}				t_col_max_width;

//FUNCTIONS//
//sort
void	argv_sort(char **argv);
int32_t	ft_lstsort(t_list **head, t_list *link);
int64_t	name_sort(void *content1, void *content2);
int64_t	size_sort(void *content1, void *content2);
int64_t	atime_sort(void *content1, void *content2);
int64_t	btime_sort(void *content1, void *content2);
int64_t	ctime_sort(void *content1, void *content2);
int64_t	mtime_sort(void *content1, void *content2);
int64_t	rev_name_sort(void *content1, void *content2);
int64_t	rev_size_sort(void *content1, void *content2);
int64_t	rev_atime_sort(void *content1, void *content2);
int64_t	rev_btime_sort(void *content1, void *content2);
int64_t	rev_ctime_sort(void *content1, void *content2);
int64_t	rev_mtime_sort(void *content1, void *content2);
int64_t	no_sort(void *content1, void *content2);

//opt
t_sopt  sopt(t_sopt *input);
void    implicit_opts(void);

//process
void	process_files(char **argv);
void	add_error(t_list **error_lst, char *err, char *file);
void	add_file(t_list **file_lst, t_stat *stat, char *dir, char *file);
void	read_dir(char **dir);
char	*path_join(char *dir, char *file);
int	check_loop(ino_t new_inode, bool reset);

//print
void	print_error_lst(t_list *error_lst);
void	print_file_lst(t_list *file_lst);
void    print_file_lst_short(t_list *file_lst);
void    print_file_lst_short_across(t_list *file_lst);
void    print_file_lst_long(t_list *file_lst);

//error
void	print_error_malloc(int err_no);
char	*str_error_access(char *err, char *file);

#endif
