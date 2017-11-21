/*	TO DO
	- hide hour if date is more than 6 months ago or in the future
	- sort when input multipe directories
	- recursive loop protect (inode check?)
	- add -@ option (currently -e)
	- sort funcs buf=gged without -l
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
  x  -U	Use time of file creation, instead of last modification for sorting (-t) or long output (-l).
  x  -x	The same as -C, except that the multi-column output is produced with entries sorted across,
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

#include "ft_ls.h"

char	*path_join(char *dir, char *file)
{
    char	*path;
    size_t	index;

    index = 0;
    path = ft_strnew(1 + ft_strlen(dir) + ft_strlen(file));
    ft_strcpy(path + index, dir);
    index += ft_strlen(dir);
    if (*(dir + ft_strlen(dir) - 1) != '/')
    {
    	ft_strcpy(path + index, "/");
    	index += 1;
    }
    ft_strcpy(path + index, file);
    return(path);
}

#define FILE_NAME (*(t_xstat*)(*file_lst).content).name
#define FILE_NAME_ISNT(name) ft_strcmp(FILE_NAME, name)
#define FILE_DIR  (*(t_xstat*)(*file_lst).content).path
#define FILE_MODE (*(*(t_xstat*)(*file_lst).content).stat).st_mode

#define REGISTERED_INODE *(ino_t*)(*tmp).content
int             check_loop(ino_t new_inode, bool reset)
{
    static t_list	*ino_lst;
    t_list		*ino_lnk;
    t_list		*tmp;

    if (reset == RESET)
    {
        //add lst_del();
        ino_lst = NULL;
    }

    ino_lnk = NULL;
    tmp = ino_lst;
    while (tmp != NULL)
    {
        if (REGISTERED_INODE == new_inode)
        {
            return(LOOP_ERROR);
        }
        tmp = (*tmp).next;
    }
    ino_lnk = ft_lstnew(&new_inode, sizeof(ino_t));
    ft_lstadd(&ino_lst, ino_lnk);
    return(0);
}
#undef REGISTERED_INODE


void	recursive(t_list *file_lst)
{
    char	*path;
    t_stat	fstat;
    int		(*stat_func)(const char *restrict, struct stat *restrict);

    if (OPT(R))
    {
    	if (OPT(L))
      	    stat_func = &stat;
    	else
            stat_func = &lstat;

    	while (file_lst != NULL)
    	{
	    	    printf("@@@@RECURSIVE CALL: %s\n", FILE_NAME);
    	    if (FILE_NAME_ISNT(".") != 0 && FILE_NAME_ISNT("..") != 0)
    	    {
	    	path = path_join(FILE_DIR, FILE_NAME);
	    	if (stat_func(path, &fstat) != 0)
	    	{
	    	    printf("cant stat %s\n", path);		
	    	}
	    	else if (S_ISDIR(FILE_MODE))
	    	{
	    	    if (check_loop(fstat.st_ino, NORESET))
	    	    {
			printf("%s: loop error\n", FILE_NAME);
	    	    }
	    	    else
	    	    {
	    	    	ft_putendl("");
	    	    	ft_putstr(path);
	    	    	ft_putendl(":");
	    	    	read_dir(&path);
	    	    }
    	    	}
    	    }
	    file_lst = (*file_lst).next;
    	}
    }
}
#undef FILE_NAME
#undef FILE_DIR

#define FILE_NAME name
int	is_printable(char *name)
{
    if (OPT(a))
    {
	return(true);
    }
    else if (OPT(A))
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

#define FILE_NAME (*direntry).d_name
void	read_dir(char **dir)
{
    DIR		*dirstream;
    t_dirent	*direntry;
    t_list	*file_lst;
    t_list	*error_lst;
    t_stat	fstat;
    char	*path;
    char	*file_name;
    int         (*stat_func)(const char *restrict, struct stat *restrict);


    dirstream = NULL;
    direntry = NULL;
    error_lst = NULL;
    file_lst = NULL;
    //fstat = NULL;
    path = NULL;
    if (OPT(L))
	stat_func = &stat;
    else
	stat_func = &lstat;
    if ((dirstream = opendir(*dir)) == NULL)
    {
//	printf("read_dir(): opendir: error\n");
	ft_putendl_fd(str_error_access(strerror(errno), *dir), 2);
	return;
    }
    while ((direntry = readdir(dirstream)) != NULL)
    {
    	if (is_printable(FILE_NAME))
    	{
    	    file_name = ft_strdup(FILE_NAME);
     	    path = path_join(*dir, file_name);
//    printf("file = %s\n", file_name);
	    if (stat_func(path, &fstat) != 0)
 	    {
//	    	printf("read_dir(): stat: error\n");
      	    	//add_error(&error_lst, strerror(errno), path);
//		ft_putendl_fd(str_error_access(strerror(errno), file_name), 2);
   	    }
    	    else
     	    {
	    	add_file(&file_lst, &fstat, *dir, FILE_NAME);
       	    }
       	}
    }
    closedir(dirstream);
    print_file_lst(file_lst);
    print_error_lst(error_lst);
    recursive(file_lst);
    //ft_lstdel(error_lst, lst_destructor);
    //ft_lstdel(file_lst, lst_destructor);
}
#undef FILE_NAME

void	process_dirs(char **argv)
{
    t_stat	fstat;
    int		(*stat_func)(const char *restrict, struct stat *restrict);
    int index;

    index = 0;
    if (OPT(L))
        stat_func = &stat;
    else
        stat_func = &lstat;

    while(*argv)
    {
	if (stat_func(*argv, &fstat) != 0);
	else if ((S_ISDIR(fstat.st_mode)))
	{
	    if (index > 0)
	    {
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

void	process_args(char **argv)
{
    process_files(argv + 1);
    process_dirs(argv + 1);
}

int		main(int argc, char **argv)
{
    t_sopt	tmp;
    size_t	index;
    char 	**defaut;

    //get options
    tmp = ft_getopt(argc, argv);
    sopt(&tmp);

    //implicit_opts
    implicit_opts();

    //sort argv
    argv_sort(argv);

    //send args to process
    index = 0;
    while (*(argv + ++index) != NULL);
    if (index == 1)
    {
	defaut = (char**)ft_memalloc(sizeof(*defaut) * 3);
	*(defaut + 1) = ft_strdup(".");
	*(defaut + 2) = NULL;
	process_args(defaut);
	ft_strdel(defaut + 1);
	ft_memdel((void**)&defaut);
    }
    else
    {
	process_args(argv);
    }


    return (0);
}

