
#include "ft_ls.h"

static int     qsort_cmp(const void *dst, const void *src)
{
    return(ft_strcmp( *(char * const *) dst, *(char * const *) src));
}

void    argv_sort(char **argv)
{
    size_t index;

    index = 0;
    while (*(argv + ++index) != NULL);
    index--;
    qsort((argv + 1), index, sizeof(char *), qsort_cmp);
}
