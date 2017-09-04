#include "ft_ls.h"
#include "libft/libft.h"

int     process_dir(char *directory)
{
        char        *error_str;
        DIR         *dir_stream;
        t_list      *dir_infos;
        char        *path;

        //printf("\n~~~Processing '%s'~~~\n", directory);

        //open dir stream
        printf("\n%s:\n", directory);
        if ((dir_stream = opendir(directory)) == NULL)
        {
                print_error_access(strerror(errno), directory);
                return(-1);
        }

        dir_infos = lst_cur_dir(dir_stream, directory);    //get dir stream

		//options mask unprinted files
		process_opt(dir_infos);

		//append some chars to files names
//		append_opt(dir_infos);

		//print current directory
		path = ft_strjoin(directory, "/");
        print_dir(dir_infos);

        //recursive call
        if ((opt & opt_R) != 0)
        {
                recursive(dir_infos, path);
                free(path);
        }

        //close dir stream
        ft_lstdel(&dir_infos, lst_destruct);
        if (closedir(dir_stream) != 0)
        {
                print_error_access(strerror(errno), directory);
                return(-1);
        }
        return(0);
}

#define content (*(t_file_infos*)(*l_dir_info).content)
#define file_name (*content.dir).d_name
#define file_siz (*content.stat).st_size
#define file_name_isnt(name) ft_strcmp(file_name, name)
#define file_print content.printable
void	process_opt(t_list *l_dir_info)
{
		while(l_dir_info != NULL)
		{
				(opt & opt_A) ? process_opt_A(l_dir_info): 0;
				(opt & opt_B) ? process_opt_B(l_dir_info): 0;
				(opt & opt_a) ? process_opt_a(l_dir_info): 0;

				l_dir_info = (*l_dir_info).next;
		}

}

void	process_opt_a(t_list *l_dir_info)
{
		file_print = true;
}

void	process_opt_A(t_list *l_dir_info)
{
		if (ft_strcmp(file_name, ".") == 0 || ft_strcmp(file_name, "..") == 0)
		{
				file_print = false;
		}
		else
		{
				file_print = true;
		}
}

void	process_opt_B(t_list *l_dir_info)
{

		if (*(file_name + (ft_strlen(file_name) - 1)) == '~')
		{
				file_print = false;
		}
		else
		{
				file_print = true;
		}
}

void recursive(t_list *l_dir_info, char *path)
{
        char    *file_path = NULL;

        while (l_dir_info != NULL)
        {

                if ((*content.dir).d_type == DT_DIR)
                {
                        if (file_name_isnt(".") != 0 && file_name_isnt("..") != 0)
                        {
                                process_dir(ft_strjoin(path, file_name));
                        }
                }
                l_dir_info = (*l_dir_info).next;
        }
}
#undef file_name
#undef file_name_isnt
#undef content

bool	get_xattr(char *dir, char *file)
{
		bool	has_xa;
		char 	*path;
		char	*xa;

		path = ft_strjoin(dir, "/");
		path = ft_strjoin(path, file);
		xa = ft_strnew(666);
		if(listxattr(path, xa, 666, 0) > 0)
		{
				has_xa = true;
		}
		else
		{
				has_xa = false;
		}
		ft_memdel((void**)&path);
		ft_memdel((void**)&xa);
		return(has_xa);
}

#define content (*(t_file_infos*)(*link).content)
#define file_name (*content.dir).d_name
t_list  *lst_cur_dir(DIR *dir_stream, char *directory)
{
        t_dirent        *s_dir;
        t_file_infos    *file_info;
        t_list          *head;
        t_list          *link;

        head = NULL;
        link = NULL;
        //Read through dir
        while ((s_dir = readdir(dir_stream)) != NULL)
        {
                file_info = (t_file_infos*)ft_memalloc(sizeof(*file_info));
                link = ft_lstnew(file_info, sizeof(*file_info));

                content.dir = s_dir;
                content.stat = get_file_stat(directory, (*s_dir).d_name);
				content.name = ft_strdup((*s_dir).d_name);

				if (*(file_name + 0) == '.')
						content.printable = false;
				else
						content.printable = true;

				content.has_xattr = get_xattr(directory, file_name);

				content.name_len = ft_strlen(file_name);

				//add to list and insertion sort
				//sort_by_opt(&head, link);
				ft_lstsort(&head, link);
        }
        return(head);
}
#undef content

t_stat	*get_file_stat(char *directory, char *file)
{
		t_stat	*file_stat;
		char 	*path;
        char	*error_str;

		file_stat = NULL;
		if ((file_stat = (t_stat*)malloc(sizeof(*file_stat))) == NULL)
		{
				print_malloc_error();
		}

		path = ft_strjoin(directory, ft_strdup("/"));
		path = ft_strjoin(path, file);
		//free strjoin
		if (stat(path, file_stat) != 0)
		{
                print_error_access(strerror(errno), path);
                return(NULL);
		}
		return(file_stat);
}

