
#include "ft_ls.h"

static int     qsort_cmp(const void *dst, const void *src)
{
    return(ft_strcmp( *(char * const *) dst, *(char * const *) src));
}

static int     rev_qsort_cmp(const void *dst, const void *src)
{
	int ret;

	ret = -ft_strcmp( *(char * const *) dst, *(char * const *) src);
    //return(-ft_strcmp( *(char * const *) dst, *(char * const *) src));
	return(ret);
}

void    argv_sort(char **argv, int argc)
{
	int index;

	index = argc - ft_optind;
	if (index > 1)
	{
		if (opt_r)
			qsort((argv), index, sizeof(char *), rev_qsort_cmp);
		else
			qsort((argv), index, sizeof(char *), qsort_cmp);
	}
}
