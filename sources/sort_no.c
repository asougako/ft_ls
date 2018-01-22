#include "ft_ls.h"

int64_t		no_sort(void *content1, void *content2)
{
		void	*c1;
		void	*c2;

		c1 = content1;
		c2 = content2;
		c1++;
		c2++;
		return(0);
}
