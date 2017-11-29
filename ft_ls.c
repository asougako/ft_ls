/*	TO DO
	- hide hour if date is more than 6 months ago or in the future
	- colplete colors (stycky bits, GID, UID...)
	- check bad args + print synopsis
	- add argv + 0 in error print
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
x	-1	Force output to be one entry per line.  This is the default when output is not to a terminal.
x	-A	List all entries except for . and ...  Always set for the super-user.
x	-c	Use time when file status was last changed for sorting (-t) or long printing (-l).
x	-d	Directories are listed as plain files (not searched recursively).
	-e	Print the Access Control List (ACL) associated with the file, if present, in long (-l) output.
x	-E	Display extended attribute keys and sizes in long (-l) output.
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
X	-p	Write a slash (`/') after each filename if that file is a directory.
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

void	check_illegal_arg(void)
{
	//if (bad arg)
	//print synopsis
	//exit (-1);
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

//	printf("Short opt:\n");
//	ft_print_short_options(sopt(NULL).opt);
//	printf("\nLong opt:\n");
//	ft_print_long_options(sopt(NULL).lopt);
//	ft_putendl("");
//	ft_putendl("");

//	check_illegal_arg();

//	if (OPTL("help"))
//	{
//		put_help();
//		return(0);
//	}

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
		process_args(defaut, index);
		ft_strdel(defaut + 1);
		ft_memdel((void**)&defaut);
	}
	else
	{
		process_args(argv, index);
	}
	return (0);
}

