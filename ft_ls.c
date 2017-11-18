#include "ft_ls.h"

/*	TO DO
	- hide hour if date is more than 6 months ago.
	- sort when input multipe directories
	- recursive loop protect (inode check?)

*/


/*base opts:
x	-l	List in long format.  (See below.)  If the output is to a ter-
	             minal, a total sum for all the file sizes is output on a line before the long listing.
x	-R	Recursively list subdirectories encountered.
x	-a	Include directory entries whose names begin with a dot (.).
x	-r	Reverse the order of the sort to get reverse lexicographical order or the oldest entries first
	             (or largest files last, if combined with sort by size
x	-t	Sort by time modified (most recently modified first) before sorting the operands by lexico-
	             graphical order.
*/

/*bonus opts:
x  	-1	Force output to be one entry per line.  This is the default when output is not to a terminal.
x	-A	List all entries except for . and ...  Always set for the super-user.
x	-c	Use time when file status was last changed for sorting (-t) or long printing (-l).
x	-d	Directories are listed as plain files (not searched recursively).
	-e	Print the Access Control List (ACL) associated with the file, if present, in long (-l) output.
	-F	Display a slash (`/') immediately after each pathname that is a directory, an asterisk (`*')
	             after each that is executable, an at sign (`@') after each symbolic link, an equals sign (`=')
	             after each socket, a percent sign (`%') after each whiteout, and a vertical bar (`|') after
	             each that is a FIFO.
x	-f	Output is not sorted.  This option turns on the -a option.
	-G	Enable colorized output.  This option is equivalent to defining CLICOLOR in the environment.
x	-g	This option is only available for compatibility with POSIX; it is used to display the group
	             name in the long (-l) format output (the owner name is suppressed).
	-H	Symbolic links on the command line are followed.  This option is assumed if none of the -F, -d,
	             or -l options are specified.
	-h	When used with the -l option, use unit suffixes: Byte, Kilobyte, Megabyte, Gigabyte, Terabyte
	             and Petabyte in order to reduce the number of digits to three or less using base 2 for sizes.
x	-i	For each file, print the file's file serial number (inode number).
	-k	If the -s option is specified, print the file size allocation in kilobytes, not blocks.  This
	             option overrides the environment variable BLOCKSIZE.
	-L	Follow all symbolic links to final target and list the file or directory the link references
	             rather than the link itself.  This option cancels the -P option.
	-m	Stream output format; list files across the page, separated by commas.
x	-n	Display user and group IDs numerically, rather than converting to a user or group name in a
	             long (-l) output.  This option turns on the -l option.
	-O	Include the file flags in a long (-l) output.
x	-o	List in long format, but omit the group id.
	-P	If argument is a symbolic link, list the link itself rather than the object the link refer-
	             ences.  This option cancels the -H and -L options.
	-p	Write a slash (`/') after each filename if that file is a directory.
x	-S	Sort files by size
	-s	Display the number of file system blocks actually used by each file, in units of 512 bytes,
	             where partial units are rounded up to the next integer value.  If the output is to a terminal,
	             a total sum for all the file sizes is output on a line before the listing.  The environment
	             variable BLOCKSIZE overrides the unit size of 512 bytes.
	-T	When used with the -l (lowercase letter ``ell'') option, display complete time information for
	             the file, including month, day, hour, minute, second, and year.
x	-t	Sort by time modified (most recently modified first) before sorting the operands by lexico-
	             graphical order.
x	-u	Use time of last access, instead of last modification of the file for sorting (-t) or long
	             printing (-l).
	-U	Use time of file creation, instead of last modification for sorting (-t) or long output (-l).
	-x	The same as -C, except that the multi-column output is produced with entries sorted across,
	             rather than down, the columns.

	     The -1, -C, -x, and -l options all override each other; the last one specified determines the format
	     used.

	     The -c and -u options override each other; the last one specified determines the file time used.

	     The -B, -b, -w, and -q options all override each other; the last one specified determines the format
	     used for non-printable characters.

	     The -H, -L and -P options all override each other (either partially or fully); they are applied in the
	     order specified.

	     By default, ls lists one entry per line to standard output; the exceptions are to terminals or when the
	     -C or -x options are specified.

	     File information is displayed with one or more <blank>s separating the information associated with the
	     -i, -s, and -l options.
*/

/*	TO BE DELETED*/
#define DIR_CONTENT  (t_file_infos*)(*(t_list*)(*dir).content).content
#define FILE_CONTENT (*(t_file_infos*)(*file)).content
void	print_dirlst(t_list *dirlst)
{
    t_list	*dir = NULL;
    t_list	*file = NULL;

    dir = dirlst;

    for (dir = dirlst; dir != NULL; dir = (*dir).next)
    {
	printf("Dir: %s\n", (*DIR_CONTENT).path);
	for (file = (*dir).content; file != NULL; file = (*file).next)
	{
	    if ((*(t_file_infos*)(*file).content).printable == 1)
		printf("\tFile v\tname: %s\n", (*(t_file_infos*)(*file).content).name);
	    else
		printf("\tFile u\tname: %s\n", (*(t_file_infos*)(*file).content).name);
	}
    }
}
#undef DIR_CONTENT
#undef FILE_CONTENT
/*__TO BE DELETED*/

void	file_lst_destructor(void *content, size_t size)
{
    ft_memdel(((void**)&(*(t_file_infos*)content).stat));
    ft_strdel(&(*(t_file_infos*)content).path);
    ft_strdel(&(*(t_file_infos*)content).name);
    ft_strdel(&(*(t_file_infos*)content).str_mode);
    ft_strdel(&(*(t_file_infos*)content).str_link);
    ft_strdel(&(*(t_file_infos*)content).str_user);
    ft_strdel(&(*(t_file_infos*)content).str_group);
    ft_strdel(&(*(t_file_infos*)content).str_major);
    ft_strdel(&(*(t_file_infos*)content).str_minor);
    ft_strdel(&(*(t_file_infos*)content).str_size);
    ft_strdel(&(*(t_file_infos*)content).str_date);
    ft_memdel(&content);
}

void	dir_lst_destructor(void *content, size_t size)
{
    ft_lstdel((t_list**)&content, &file_lst_destructor);
    ft_memdel(	&content	);
}

void	lst_destructor(t_list **dirlst)
{
    ft_lstdel(dirlst, &dir_lst_destructor);
}

char *join_slash(char *dir, char *file)
{
    char *ret;
    char *tmp;

    ret = NULL;
    if (dir == NULL)
	return(ft_strdup(file));
    ret = ft_strnew(ft_strlen(dir) + ft_strlen(file) + 1);
    tmp = ret;
    while (*dir)
	*tmp++ = *dir++;
    *tmp++ = '/';
    while (*file)
	*tmp++ = *file++;
    return(ret);

}

t_list	*lst_cur_dir_error(char *strerror, char *path)
{
	t_list		*file_lst;
	t_list		*file_link;
	t_file_infos	*file_info;

	file_lst = NULL;
	file_link = NULL;
	file_info = NULL;

	file_info = (t_file_infos*)ft_memalloc(sizeof(*file_info));
	(*file_info).path = ft_strdup(path);
	(*file_info).name = str_error_access(strerror, path);
	(*file_info).error_access = true;
	file_link = ft_lstnew(NULL, sizeof(file_info));
	(*file_link).content = file_info;
	return(file_link);
}

void    dirlst_add_dir(t_list **dirlst, char *path)
{
    t_list      *new_dir_lnk = NULL;
    t_list      *new_file_lst = NULL;
    DIR         *dir_stream;


    //Open dir stream
    if ((dir_stream = opendir(path)) == NULL)
    {
	new_file_lst = lst_cur_dir_error(strerror(errno), path);
    }
    else
    {
    	//List files
    	new_file_lst = lst_cur_dir(dir_stream, path);
    	//Close dir stream
    	closedir(dir_stream);
    }

    //Create dir link
    new_dir_lnk = ft_lstnew(NULL, sizeof(new_file_lst));
    (*new_dir_lnk).content = new_file_lst;

    //Add dir link to dirlst
    ft_lstadd_tail(dirlst, new_dir_lnk);

    //Recursive
    recursive(dirlst, new_file_lst, path);
}

void	dirlst_add_file(t_list **dirlst, char *path)
{
    static bool		done;
    static t_list	*dir_link;
    static t_list	*file_list;
    t_list			*file_link;

    file_link = NULL;

    //Add file list to dir list
    if (!done)
    {
	dir_link = ft_lstnew(NULL, sizeof(file_list));
	ft_lstadd(dirlst, dir_link);
	done = 1;
    }

    //Create new link & get file_infos
    file_link = ft_lstnew(NULL, sizeof(t_file_infos*));
    (*file_link).content = get_file_infos(NULL, path);

    //add new link to file list
    ft_lstsort(&file_list, file_link);

    //Linking file list with dir link
    (*dir_link).content = file_list;
}

#define PATH *(argv + index)
#define FILE_MODE stat_buff.st_mode
size_t	get_dirlst(char **argv, t_list **dirlst)
{
    struct stat	stat_buff;
    size_t		index;
    int	(*stat_func)(const char *restrict, struct stat *restrict);


    if (OPT(H))
    {
	stat_func = &stat;
    }
    else
    {
	stat_func = &lstat;
    }
    index = 1;
    while (PATH)
    {
	if (stat_func(PATH, &stat_buff) == -1)
	{
	    print_error_access(strerror(errno), PATH);
	}
	else if (S_ISDIR(FILE_MODE))
	{
	    //printf("1\t%s = %o (%d)\n", PATH, FILE_MODE, S_ISLNK(FILE_MODE));
	    if (OPT(d))
	    {
	    	dirlst_add_file(dirlst, PATH);
	    }
	    else
	    {
	    	dirlst_add_dir(dirlst, PATH);
	    }
	}
	else
	{
	    dirlst_add_file(dirlst, PATH);
	}
	index++;
    }
    return(index);
}
#undef PATH
#undef FILE_MODE

void	process_opt(t_list *file_list)
{
    process_printable(file_list);
}

void	process_opt_old(t_list *dirlst)
{
    t_list *file_list;

    file_list = NULL;
    while (dirlst != NULL)
    {
	file_list = (t_list*)(*dirlst).content;
	process_printable(file_list);
	dirlst = (*dirlst).next;
    }
}

void	implicit_opts(void)
{
    t_sopt	opts;

    opts = sopt(NULL);
    OPT(f) ? opts.opt |= opt_a : 0;
    OPT(n) ? opts.opt |= opt_l : 0;
    OPT(d) ? opts.opt |= opt_a : 0;
    OPT(L) ? opts.opt |= opt_H : 0;
    sopt(&opts);
}

int		main(int argc, char **argv)
{
    t_sopt	tmp;
    t_list	*dirlst;
    size_t	index;
    char 	**defaut;

    /*	GET OPT	*/
    tmp = ft_getopt(argc, argv);		//get options
    sopt(&tmp);							//put options in fake global
//    printf("Short opt:\n");
//    ft_print_short_options(sopt(NULL).opt);
//    printf("\nLong opt:\n");
//    ft_print_long_options(sopt(NULL).lopt);
//    ft_putendl("");
//    ft_putendl("");
    /*__GET OPT	*/

    /*implicit_opts*/
    implicit_opts();
    /*implicit_opts*/


    /*GET_DIRLST*/
    dirlst = NULL;
    index = 0;
    while (*(argv + ++index) != NULL);
    if (index == 1)
    {
    	defaut = (char**)ft_memalloc(sizeof(*defaut) * 3);
    	*(defaut + 1) = ft_strdup(".");
    	*(defaut + 2) = NULL;
    	index = get_dirlst(defaut, &dirlst);	//list all dirs, put orphans files in a fake dir.
    	ft_strdel(defaut + 1);
    	ft_memdel((void**)&defaut);
    }
    else
    {
    	index = get_dirlst(argv, &dirlst);	//list all dirs, put orphans files in a fake dir.
    }
    /*__GET_DIRLST*/


    /*	PROCESS OPT*/
    //    process_opt(dirlst);		//moved to print_dir()
    /*__PROCESS OPT*/


    /*PRINT*/
    //printf("\nPrint dirlst:\n");
    //print_dirlst(dirlst);
    print_dir(dirlst, index);
    /*__PRINT*/

    /*MEM_FREE*/
    lst_destructor(&dirlst);
    /*__MEM_FREE*/

    return (0);
}
