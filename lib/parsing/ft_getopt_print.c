
#include "ft_getopt.h"

void            ft_print_short_options(uint64_t params)
{
		int     index;
		char    tmp_char;

		index = 0;
		while (params != 0)
		{
				if ((params & 1ull) == 1)
				{
						if (index < 10)
								tmp_char = '0' + index;
						else if(index < 36)
								tmp_char = 'A' + (index - 10);
						else
								tmp_char = 'a' + (index - 36);
						write(1, &tmp_char, 1);
				}
				params >>= 1;
				index++;
		}
}

void            ft_print_long_options(t_list *opt_lst)
{
		while (opt_lst != NULL)
		{
				if ((*(t_loption*)(*opt_lst).content).value != NULL)
				{
						ft_putstr((*(t_loption*)(*opt_lst).content).name);
						ft_putstr(" = ");
						ft_putendl((*(t_loption*)(*opt_lst).content).value);
				}
				else
				{
						ft_putendl((*(t_loption*)(*opt_lst).content).name);
				}
				opt_lst = (*opt_lst).next;
		}
}
