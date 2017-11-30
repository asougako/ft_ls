/*	TO DO
	- hide hour if date is more than 6 months ago or in the future
	- SEGV /private/etc
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
x	-@	Display extended attribute keys and sizes in long (-l) output.
x	-1	Force output to be one entry per line.  This is the default when output is not to a terminal.
x	-A	List all entries except for . and ...  Always set for the super-user.
x	-c	Use time when file status was last changed for sorting (-t) or long printing (-l).
x	-d	Directories are listed as plain files (not searched recursively).
	-e	Print the Access Control List (ACL) associated with the file, if present, in long (-l) output.
x	-F	Display a slash (`/') immediately after each pathname that is a directory, an asterisk (`*')
			after each that is executable, an at sign (`@') after each symbolic link, an equals sign (`=')
			after each socket, a percent sign (`%') after each whiteout, and a vertical bar (`|') after
			each that is a FIFO.
x	-f	Output is not sorted.  This option turns on the -a option.
X	-G	Enable colorized output.  This option is equivalent to defining CLICOLOR in the environment.
x	-g	This option is only available for compatibility with POSIX; it is used to display the group
			name in the long (-l) format output (the owner name is suppressed).
x	-H	Symbolic links on the command line are followed.  This option is assumed if none of the -F, -d,
			or -l options are specified.
	-h	When used with the -l option, use unit suffixes: Byte, Kilobyte, Megabyte, Gigabyte, Terabyte
			and Petabyte in order to reduce the number of digits to three or less using base 2 for sizes.
x	-i	For each file, print the file's file serial number (inode number).
	-k	If the -s option is specified, print the file size allocation in kilobytes, not blocks.  This
			option overrides the environment variable BLOCKSIZE.
x	-L	Follow all symbolic links to final target and list the file or directory the link references
			rather than the link itself.  This option cancels the -P option.
x	-m	Stream output format; list files across the page, separated by commas.
x	-n	Display user and group IDs numerically, rather than converting to a user or group name in a
			long (-l) output.  This option turns on the -l option.
x	-o	List in long format, but omit the group id.
x	-P	If argument is a symbolic link, list the link itself rather than the object the link refer-
			ences.  This option cancels the -H and -L options.
x	-p	Write a slash (`/') after each filename if that file is a directory.
x	-S	Sort files by size
x	-T	When used with the -l (lowercase letter ``ell'') option, display complete time information for
			the file, including month, day, hour, minute, second, and year.
x	-t	Sort by time modified (most recently modified first) before sorting the operands by lexico-
			graphical order.
x	-u	Use time of last access, instead of last modification of the file for sorting (-t) or long
			printing (-l).
x	-U	Use time of file creation, instead of last modification for sorting (-t) or long output (-l).
x	-x	The same as -C, except that the multi-column output is produced with entries sorted across,
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

t_bool opt_at;
t_bool opt_1;
t_bool opt_A;
t_bool opt_a;
t_bool opt_c;
t_bool opt_d;
t_bool opt_e;
t_bool opt_F;
t_bool opt_f;
t_bool opt_G;
t_bool opt_g;
t_bool opt_H;
t_bool opt_h;
t_bool opt_i;
t_bool opt_k;
t_bool opt_l;
t_bool opt_L;
t_bool opt_m;
t_bool opt_n;
t_bool opt_o;
t_bool opt_P;
t_bool opt_p;
t_bool opt_R;
t_bool opt_r;
t_bool opt_S;
t_bool opt_T;
t_bool opt_t;
t_bool opt_U;
t_bool opt_u;
t_bool opt_x;

#define VALID_OPT "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1@"
void	put_synopsis(void)
{
	ft_putstr("usage: ft_ls [-");
	ft_putstr(VALID_OPT);
	ft_putendl("] [file ...]");
	exit(EXIT_FAILURE);
}

void	get_options(int argc, char *argv[])
{
	int opt;

	opt = 0;
	while ((opt = ft_getopt(argc, argv, VALID_OPT)) != -1)
	{
		opt == '@'? opt_at = true: 0;
		opt == '1'? opt_1 = true: 0;
		opt == 'A'? opt_A = true: 0;
		opt == 'a'? opt_a = true: 0;
		opt == 'c'? opt_c = true: 0;
		opt == 'd'? opt_d = true: 0;
		opt == 'e'? opt_e = true: 0;
		opt == 'F'? opt_F = true: 0;
		opt == 'f'? opt_f = true: 0;
		opt == 'G'? opt_G = true: 0;
		opt == 'g'? opt_g = true: 0;
		opt == 'H'? opt_H = true: 0;
		opt == 'h'? opt_h = true: 0;
		opt == 'i'? opt_i = true: 0;
		opt == 'k'? opt_k = true: 0;
		opt == 'l'? opt_l = true: 0;
		opt == 'L'? opt_L = true: 0;
		opt == 'm'? opt_m = true: 0;
		opt == 'n'? opt_n = true: 0;
		opt == 'o'? opt_o = true: 0;
		opt == 'P'? opt_P = true: 0;
		opt == 'p'? opt_p = true: 0;
		opt == 'R'? opt_R = true: 0;
		opt == 'r'? opt_r = true: 0;
		opt == 'S'? opt_S = true: 0;
		opt == 'T'? opt_T = true: 0;
		opt == 't'? opt_t = true: 0;
		opt == 'U'? opt_U = true: 0;
		opt == 'u'? opt_u = true: 0;
		opt == 'x'? opt_x = true: 0;
		opt == '?'? put_synopsis(): 0;
	}
}

int		main(int argc, char **argv)
{
	char 	**defaut;

	//get options
	get_options(argc, argv);

	//	if (OPTL("help"))
	//	{
	//		put_help();
	//		return(0);
	//	}

	//sort argv
	argv_sort(argv + ft_optind);

	//send args to process
	int index = 0;
	while (*(argv + index) != NULL)
	{
//		printf("argv[%d] = %s\n", index, *(argv + index));
		index++;
	}
	if ((argc - ft_optind) == 0)
	{
		defaut = (char**)ft_memalloc(sizeof(*defaut) * 3);
		*(defaut + 1) = ft_strdup(".");
		*(defaut + 2) = NULL;
		process_args(defaut, ft_optind);
		ft_strdel(defaut + 1);
		ft_memdel((void**)&defaut);
	}
	else
	{
		process_args(argv + ft_optind, argc);
	}
	return (0);
}

