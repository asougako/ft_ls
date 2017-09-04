#include "ft_ls.h"

#define file_size(INDEX) (*(*((t_file_infos*)content ## INDEX)).stat).st_size
#define file_name(INDEX) (*(*((t_file_infos*)content ## INDEX)).dir).d_name

int		size_sort(void *content1, void *content2)
{
		if (file_size(1) == file_size(2))
		{
				return(name_sort(content1, content2));
		}
		else
		{
				return(file_size(2) - file_size(1));
		}
}

int		rev_size_sort(void *content1, void *content2)
{
		return(-size_sort(content1, content2));
}
#undef file_size
#undef file_name