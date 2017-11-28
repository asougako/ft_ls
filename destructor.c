
#include "ft_ls.h"

void    inolst_destructor(void *content, size_t size)
{
	size++;
	ft_memdel((void**)&content);
}

void    errlst_destructor(void *content, size_t size)
{
	size++;
	ft_memdel((void**)&content);
}

void    lst_destructor(void *content, size_t size)
{
	size++;
	ft_memdel((void**)&((*(t_xstat*)content).stat));
	ft_memdel((void**)&((*(t_xstat*)content).path));
	ft_memdel((void**)&((*(t_xstat*)content).name));
	ft_memdel((void**)&((*(t_xstat*)content).xattr));
	ft_memdel((void**)&((*(t_xstat*)content).acl));
	ft_memdel((void**)&((*(t_xstat*)content).error));
	ft_memdel((void**)&((*(t_xstat*)content).str_inode));
	ft_memdel((void**)&((*(t_xstat*)content).str_mode));
	ft_memdel((void**)&((*(t_xstat*)content).str_link));
	ft_memdel((void**)&((*(t_xstat*)content).str_user));
	ft_memdel((void**)&((*(t_xstat*)content).str_group));
	ft_memdel((void**)&((*(t_xstat*)content).str_major));
	ft_memdel((void**)&((*(t_xstat*)content).str_minor));
	ft_memdel((void**)&((*(t_xstat*)content).str_size));
	ft_memdel((void**)&((*(t_xstat*)content).str_date));
	ft_memdel((void**)&content);
}
