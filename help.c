/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:38:32 by asougako          #+#    #+#             */
/*   Updated: 2017/12/01 16:36:50 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_help(void)
{
	ft_putendl("-@  Display extended attribute keys and sizes in long (-l) \
output.");
	ft_putendl("-1  Force output to be one entry per line.");
	ft_putendl("-A  List all entries except for . and ...");
	ft_putendl("-a  Include directory entries whose names begin with a dot(.).");
	ft_putendl("-c  Use time when file status was last changed for sorting (-t) or long printing (-l).");
	ft_putendl("-d  Directories are listed as plain files (not searched	recursively).");
	ft_putendl("-e  Print the Access Control List (ACL) associated with the	file, if present, in long (-l) output.");
	ft_putendl("-F  Display a slash (`/') immediately after each pathname that is a directory, an asterisk (`*') after each that is executable,	an at sign (`@') after each symbolic link, an equals sign (`=')	after each socket, a percent sign (`%') after each whiteout, and a vertical bar (`|') after each that is a FIFO.");
	ft_putendl("-f  Output is not sorted. This option turns on the -a option.");
	ft_putendl("-G  Enable colorized output.  This option is equivalent to defining CLICOLOR in the environment.");
	ft_putendl("-g  This option is only available for compatibility with POSIX; it is used to display the group name in the long (-l) format output	(the owner name is suppressed).");
	ft_putendl("-H  Symbolic links on the command line are followed. This\
		   	option is assumed if none of the -F, -d, or -l options are\
		   	specified.");
	ft_putendl("-h  When used with the -l option, use unit suffixes: Byte,\
		   	Kilobyte, Megabyte, Gigabyte, Terabyte and Petabyte in order to\
		   	reduce the number of digits to three or less using base 2 for\
		   	sizes.");
	ft_putendl("-i  For each file, print the file's file serial number (inode\
			number).");
	ft_putendl("-I  Output this options infos.");
	ft_putendl("-k  If the -s option is specified, print the file size\
		   	allocation in kilobytes, not blocks. This option overrides the\
		   	environment variable BLOCKSIZE.");
	ft_putendl("-L  Follow all symbolic links to final target and list the\
		   	file or directory the link references rather than the link itself.\
		  	This option cancels the -P option.");
	ft_putendl("-l  List in long format. If the output is to a terminal, a\
		   	total sum for all the file sizes is output on a line before the\
		   	long listing.");
	ft_putendl("-m  Stream output format; list files across the page,\
		   	separated by commas.");
	ft_putendl("-n  Display user and group IDs numerically, rather than\
		   	converting to a user or group name in a long (-l) output. This \
			option turns on the -l option.");
	ft_putendl("-o  List in long format, but omit the group id.");
	ft_putendl("-P  If argument is a symbolic link, list the link itself \
			rather than the object the link references. This option cancels \
			the -H and -L options.");
	ft_putendl("-p  Write a slash (`/') after each filename if that file is a \
			directory.");
	ft_putendl("-R  Recursively list subdirectories encountered.");
	ft_putendl("-r  Reverse the order of the sort to get reverse \
			lexicographical order or the oldest entries first (or largest\
			   	files last, if combined with sort by size)");
	ft_putendl("-S  Sort files by size");
	ft_putendl("-T  When used with the -l (lowercase letter ``ell'') option,\
		   	display complete time information for the file, including month, \
			day, hour, minute, second, and year.");
	ft_putendl("-t  Sort by time modified (most recently modified first) \
			before sorting the operands by lexico graphical order.");
	ft_putendl("");
	ft_putendl("-u  Use time of last access, instead of last modification of \
			the file for sorting (-t) or long printing (-l).");
	ft_putendl("-U  Use time of file creation, instead of last modification \
			for sorting (-t) or long output (-l).");
	ft_putendl("-x  The same as -C, except that the multi-column output is \
			produced with entries sorted across, rather than down, the c\
			olumns.");
}
