/*
   Base  -l, -R, -a, -r, -t
   l   List in long format.
   R   Recursively list subdirectories encountered.
   a   Include directory entries whose names begin with a dot (.).
   r   Reverse the order of the sort.
   t   Sort by time modified.

   Bonus -u, -f, -g, -d, -h, -F
x   -a, --all
   do not ignore entries starting with .

x   -A, --almost-all
   do not list implied . and ..

   --block-size=SIZE
   scale sizes by SIZE before printing them; e.g., '--block-size=M' prints sizes in units of 1,048,576 bytes; see SIZE format below

x   -B, --ignore-backups
   do not list implied entries ending with ~

x   -c     with -lt: sort by, and show, ctime (time of last modification of file status information); with -l: show ctime and sort by name; otherwise: sort by ctime, newest first

   --color[=WHEN]
   colorize the output; WHEN can be 'always' (default if omitted), 'auto', or 'never'; more info below

   -d, --directory
   list directories themselves, not their contents

x   -f     do not sort, enable -aU, disable -ls --color

   -F, --classify
   append indicator (one of *=>/@|) to entries

   --file-type
   likewise, except do not append '*'

   --full-time
   like -l --time-style=full-iso

   -g     like -l, but do not list owner

   --group-directories-first
   group directories before files;

   can be augmented with a --sort option, but any use of --sort=none (-U) disables grouping

   -G, --no-group
   in a long listing, don't print group names

   -h, --human-readable
   with -l and/or -s, print human readable sizes (e.g., 1K 234M 2G)

   --si   likewise, but use powers of 1000 not 1024

   -i, --inode
   print the index number of each file

   -k, --kibibytes
   default to 1024-byte blocks for disk usage

x   -l     use a long listing format

   -L, --dereference
   when showing file information for a symbolic link, show information for the file the link references rather than for the link itself

   -m     fill width with a comma separated list of entries

   -n, --numeric-uid-gid
   like -l, but list numeric user and group IDs

	-o     like -l, but do not list group information

	-p, --indicator-style=slash
	append / indicator to directories

	-Q, --quote-name
	enclose entry names in double quotes

x	-r, --reverse
	reverse order while sorting

x	-R, --recursive
	list subdirectories recursively

	-s, --size
	print the allocated size of each file, in blocks

x	-S     sort by file size, largest first

	--sort=WORD
	sort by WORD instead of name: none (-U), size (-S), time (-t), version (-v), extension (-X)

	--time=WORD
	with -l, show time as WORD instead of default modification time: atime or access or use (-u); ctime or status (-c); also use specified time as sort key if --sort=time (newest first)

x	-t     sort by modification time, newest first

x	-u     with -lt: sort by, and show, access time; with -l: show access time and sort by name; otherwise: sort by access time, newest first

x	-U     do not sort; list entries in directory order

	-v     natural sort of (version) numbers within text

	-w, --width=COLS
	set output width to COLS.  0 means no limit

	-X     sort alphabetically by entry extension

	-Z, --context
	print any security context of each file

x	-1     list one file per line.  Avoid '\n' with -q or -b

x	--help display this help and exit

--version
output version information and exit

The SIZE argument is an integer and optional unit (example: 10K is 10*1024).  Units are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB,... (powers of 1000).

Using color to distinguish file types is disabled both by default and with --color=never.  With --color=auto, ls emits color codes only when standard output is connected to a  terminal.   The  LS_COLORS  environment
variable can change the settings.  Use the dircolors command to set it.

Parsing arguments.
Liste chainee, un maillon par fichier, contenant tous les attributs.
Trier par un attribut, selon les parametres passes.
Affichage(+errors).
Return.

Todo:
test invalid options
test ls -R with back path link
recode GNU env access
make func like ft_strjoin() with va_arg
How does errno.c to get argv addr
*/

#include "ft_ls.h"

#define FILE_MODE file_stat.st_mode
int		arg_is_a_file(char *file_path)
{
		t_stat	file_stat;

		if (stat(file_path, &file_stat) != 0)
		{
				print_error_access(strerror(errno), file_path);
				return(-1);
		}
		if(S_ISDIR(FILE_MODE))
		{
				return(0);
		}
		else
		{
				return(1);
		}
}
#undef FILE_MODE


int		main(int argc, char **argv)
{
		/***TestS***/
//		test();
		/***TestS***/

		/***Options***/
		opt = ft_getopt(argc, argv, &long_opt);	//get options
		printf("Options:\n");
		ft_print_short_options(opt);
		ft_putendl("");
		printf("Long options:\n");
		ft_print_long_options(long_opt);
		ft_putendl("");
		/***Options***/

//		if (ft_get_long_opt(long_opt, "help") != 0)
//		{
//				print_help();
//				return(0);
//		}

		/***Arguments***/

		if (argc == 1)
				process_dir(".");

		int index;
		index = 1;
		while (index <= argc)
		{
				if (*(argv + index) != NULL)
				{
						printf("process_dir(%s)\n", *(argv + index));
						if (arg_is_a_file(*(argv + index)))
								process_file(*(argv + index));
						else
								process_dir(*(argv + index));
				}
				index++;
		}

		/***Arguments***/
		return(0);
}

void	lst_destruct(void *cont, size_t size)
{
		ft_memset(cont, '\0', size);
		ft_memdel(cont);
}

