
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
	-I	Options infos.
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
x	-u	Use time of last access, instead of last modification of the file for sorting (-t) or long
			printing (-l).
x	-U	Use time of file creation, instead of last modification for sorting (-t) or long output (-l).
x	-x	The same as -C, except that the multi-column output is produced with entries sorted across,
			rather than down, the columns.

  The -1, -C, -x, and -l options all override each other; the last one specified determines the format
  used.

  The -c and -u options override each other; the last one specified determines the file time used.

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
t_bool opt_C;
t_bool opt_c;
t_bool opt_d;
t_bool opt_e;
t_bool opt_F;
t_bool opt_f;
t_bool opt_G;
t_bool opt_g;
t_bool opt_H;
t_bool opt_h;
t_bool opt_I;
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

#define VALID_OPT "ACFGHILPRSTUacdefghiklmnoprtux1@"
void	put_synopsis(void)
{
	ft_putstr_fd("usage: ft_ls [-", 2);
	ft_putstr_fd(VALID_OPT, 2);
	ft_putendl_fd("] [file ...]", 2);
	exit(EXIT_FAILURE);
}

void	get_options(int argc, char *argv[])
{
	int opt;

	opt = 0;
	while ((opt = ft_getopt(argc, argv, VALID_OPT)) != -1)
	{
		if (opt == '@')
			opt_at = true;
		if (opt == '1')
		{
			opt_1 = true;
			opt_C = false;
			opt_m = false;
			opt_l = false;
			opt_x = false;
		}
		if (opt == 'A')
			opt_A = true;
		if (opt == 'a')
			opt_a = true;
		if (opt == 'C')
		{
			opt_1 = false;
			opt_l = false;
			opt_m = false;
			opt_x = false;
		}
		if (opt == 'c')
		{
			opt_c = true;
			opt_U = false;
			opt_u = false;
		}
		if (opt == 'd')
			opt_d = true;
		if (opt == 'e')
			opt_e = true;
		if (opt == 'F')
		{
			opt_F = true;
			opt_p = false;
		}
		if (opt == 'f')
			opt_f = true;
		if (opt == 'G')
			opt_G = true;
		if (opt == 'g')
		{
			opt_g = true;
			opt_l = true;
			opt_C = false;
			opt_1 = false;
			opt_m = false;
			opt_x = false;
		}
		if (opt == 'H')
			opt_H = true;
		if (opt == 'h')
			opt_h = true;
		if (opt == 'I')
			opt_I = true;
		if (opt == 'i')
			opt_i = true;
		if (opt == 'k')
			opt_k = true;
		if (opt == 'l')
		{
			opt_l = true;
			opt_C = false;
			opt_1 = false;
			opt_m = false;
			opt_x = false;
		}
		if (opt == 'L')
			opt_L = true;
		if (opt == 'm')
		{
			opt_m = true;
			opt_1 = false;
			opt_C = false;
			opt_l = false;
			opt_x = false;
		}
		if (opt == 'n')
			opt_n = true;
		if (opt == 'o')
		{
			opt_o = true;
			opt_l = true;
			opt_C = false;
			opt_1 = false;
			opt_m = false;
			opt_x = false;
		}
		if (opt == 'P')
			opt_P = true;
		if (opt == 'p')
		{
			opt_p = true;
			opt_F = false;
		}
		if (opt == 'R')
			opt_R = true;
		if (opt == 'r')
			opt_r = true;
		if (opt == 'S')
			opt_S = true;
		if (opt == 'T')
			opt_T = true;
		if (opt == 't')
			opt_t = true;
		if (opt == 'U')
		{
			opt_U = true;
			opt_c = false;
			opt_u = false;
		}
		if (opt == 'u')
		{
			opt_u = true;
			opt_c = false;
			opt_U = false;
		}
		if (opt == 'x')
		{
			opt_x = true;
			opt_1 = false;
			opt_C = false;
			opt_m = false;
			opt_l = false;
		}
		if (opt == '?')
			put_synopsis();
	}
}

int		main(int argc, char **argv)
{
	char 	**defaut;

	//get options
	get_options(argc, argv);

	implicit_opts();

	if (opt_I)
	{
		put_help();
		return(0);
	}

	//sort argv
	argv_sort(argv + ft_optind, argc);

	//send args to process
	if ((argc - ft_optind) == 0)
	{
		defaut = (char**)ft_memalloc(sizeof(*defaut) * 2);
		*(defaut + 0) = ft_strdup(".");
		*(defaut + 1) = NULL;
		process_args(defaut, ft_optind);
		ft_strdel(defaut + 0);
		ft_memdel((void**)&defaut);
	}
	else
	{
		process_args(argv + ft_optind, argc);
	}

	char	*str;
	int		size;

//	printf("\n");

	str = ft_strdup("\e[42;30mabcdefg\e[0m");
	size = (int)ft_strlen_color(str);

//	pf(str, s);
//	pf(size, d);

	return (0);
}

