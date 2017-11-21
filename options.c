
#include "ft_ls.h"

t_sopt  sopt(t_sopt *input)
{
		static t_sopt   opt;
		if (input != NULL)
		{
				opt = *input;
		}
		return (opt);
}

void    implicit_opts(void)
{
    t_sopt  opts;

    opts = sopt(NULL);
    OPT(f) ? opts.opt |= opt_a : 0;
    OPT(n) ? opts.opt |= opt_l : 0;
    OPT(d) ? opts.opt |= opt_a : 0;
    OPT(L) ? opts.opt |= opt_H : 0;
    sopt(&opts);
}
