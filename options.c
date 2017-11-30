
#include "ft_ls.h"

void    implicit_opts(void)
{
//	t_sopt  opts;

//	opts = sopt(NULL);

	//	-f turns on the -a option
//	if (OPT(f))
//		opts.opt |= opt_a;

	//	-n turns on the -l option.
//	if (OPT(n))
//		opts.opt |= opt_l;

	//	-L implicit opt H
//	if (OPT(L))
//		opts.opt |= opt_H;

	// -L cancel -P
//	if (OPT(L))
//		opts.opt &= ~opt_P;

	//	-H  is assumed if none of the -F, -d, or -l options are specified.
//	if (!(OPT(d)) && !(OPT(l)) && !(OPT(F)))
//		opts.opt |= opt_H;

	// -P cancel -H
//	if (OPT(P))
//		opts.opt &= ~opt_H;

//	sopt(&opts);
}
