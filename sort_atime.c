#include "ft_ls.h"

#define file_atime(INDEX) (*(*((t_file_infos*)content ## INDEX)).stat).st_atime
#define file_name(INDEX) (*(*((t_file_infos*)content ## INDEX)).dir).d_name

int64_t		atime_sort(void *content1, void *content2)
{
		if (file_atime(1) == file_atime(2))
		{
				return(name_sort(content1, content2));
        }
        else
        {
				return(file_atime(2) - file_atime(1));
		}
}

int64_t		rev_atime_sort(void *content1, void *content2)
{
		return(-atime_sort(content1, content2));
}
