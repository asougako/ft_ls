
#include "ft_ls.h"

void    implicit_opts(void)
{
	//	-f turns on the -a option
	if (opt_f)
		opt_a = true;
//		opts.opt |= opt_a;

	//	-n turns on the -l option.
	if (opt_n)
		opt_l = true;
//		opts.opt |= opt_l;

	//	-L implicit opt H
	if (opt_L)
		opt_H = true;
//		opts.opt |= opt_H;

	// -L cancel -P
	if (opt_L)
		opt_P = false;
//		opts.opt &= ~opt_P;

	//	-H  is assumed if none of the -F, -d, or -l options are specified.
	if (!opt_F && !opt_d && !opt_l)
		opt_H = false;
//	if (!(OPT(d)) && !(OPT(l)) && !(OPT(F)))
//		opts.opt |= opt_H;

	// -P cancel -H
	if (opt_P)
		opt_H = false;
//	if (OPT(P))
//		opts.opt &= ~opt_H;

//	sopt(&opts);
}
