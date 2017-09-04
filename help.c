#include "ft_ls.h"
#include "libft/libft.h"
#include <stdio.h>

#define m_help(INDEX) ft_putendl(help_ ## INDEX)

#define help_1 "Usage: ls [OPTION]... [FILE]..."
#define help_2 "List information about the FILEs (the current directory by default)"
#define help_3 "Sort entries alphabetically if none of -cftuvSUX nor --sort is specified."
#define help_4 ""
#define help_5 "Mandatory arguments to long options are mandatory for short options too."
#define help_6 "  -a, --all                  do not ignore entries starting with ."

void	print_help(void)
{
		ft_putendl("");
		m_help(1);
		m_help(2);
		m_help(3);
		m_help(4);
		m_help(5);
		m_help(6);
}
