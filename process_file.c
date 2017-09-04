#include "ft_ls.h"

#define content (*(t_file_infos*)(*link).content)
#define file_name (*content.dir).d_name

static t_stat  *file_stat(char *file)
{
		t_stat  *file_stat;
		char    *error_str;

		file_stat = NULL;
		if ((file_stat = (t_stat*)malloc(sizeof(*file_stat))) == NULL)
		{
				print_malloc_error();
		}

		//free strjoin
		if (stat(file, file_stat) != 0)
		{
				print_error_access(strerror(errno), file);
				return(NULL);
		}
		return(file_stat);
}

static bool    xattr(char *file)
{
        bool    has_xa;
        char    *xa;

        xa = ft_strnew(666);
        if(listxattr(file, xa, 666, 0) > 0)
        {
                has_xa = true;
        }
        else
        {
                has_xa = false;
        }
        ft_memdel((void**)&xa);
        return(has_xa);
}


int     process_file(char *file_path)
{
		t_file_infos    *file_info;
		t_list          *head;
		t_list          *link;

		head = NULL;
		link = NULL;

		file_info = (t_file_infos*)ft_memalloc(sizeof(*file_info));
		link = ft_lstnew(file_info, sizeof(*file_info));

		content.dir = NULL;
		content.stat = file_stat(file_path);
		content.name = ft_strdup(file_path);

		content.printable = true;

		content.has_xattr = xattr(file_path);
		content.name_len = 0;

		print_dir(link);

		return(0);
}

