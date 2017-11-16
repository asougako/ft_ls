
#include "ft_ls.h"

static int64_t (*choose_sort_func(void))(void*, void*)
{
    int64_t (*sort_func_ptr)(void*, void*);

    if (OPT(r))
    {
	sort_func_ptr = &rev_name_sort; //default
	(OPT(S)) ? sort_func_ptr = &rev_size_sort: 0;//    size
	(OPT(t)) ? sort_func_ptr = &rev_mtime_sort: 0; //  m_time
	if ((OPT(l)) && !(OPT(t)));
	else
	{
	    (OPT(u)) ? sort_func_ptr = &rev_atime_sort: 0; //  atime
	    (OPT(c)) ? sort_func_ptr = &rev_ctime_sort: 0; //  ctime
	}
    }
    else
    {
	sort_func_ptr = &name_sort; //default
	(OPT(S)) ? sort_func_ptr = &size_sort: 0;//    size
	(OPT(t)) ? sort_func_ptr = &mtime_sort: 0; //  m_time
	if ((OPT(l)) && !(OPT(t)));
	else
	{
	    (OPT(u)) ? sort_func_ptr = &atime_sort: 0; //  atime
	    (OPT(c)) ? sort_func_ptr = &ctime_sort: 0; //  ctime
	}
    }
    (OPT(U) || OPT(f)) ? sort_func_ptr = &no_sort: 0;
    return(sort_func_ptr);
}

int     ft_lstsort(t_list **head, t_list *link)
{
    static int64_t (*sort_func)(void*, void*);
    t_list	**index;
    int		added;

    if (sort_func == NULL)
	sort_func = choose_sort_func();
    index = head;
    added = 0;
    while (*index != NULL)
    {
	if (((*sort_func)((*link).content, (**index).content)) < 0)
	{
	    (*link).next = *index;
	    *index = link;
	    added = 1;
	    break;
	}
	index = &((**index).next);
    }
    if (added == 0)
    {
	*index = link;
    }
    return(1);
}

