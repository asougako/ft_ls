#include "ft_ls.h"

#define file_mtime(INDEX) (*(*((t_xstat*)content ## INDEX)).stat).st_mtime
int64_t		mtime_sort(void *content1, void *content2)
{
    if (file_mtime(1) == file_mtime(2))
    {
	return(name_sort(content1, content2));
    }
    else
    {
	return(file_mtime(2) - file_mtime(1));
    }
}

int64_t		rev_mtime_sort(void *content1, void *content2)
{
    return(-mtime_sort(content1, content2));
}
