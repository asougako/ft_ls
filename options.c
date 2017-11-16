
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
