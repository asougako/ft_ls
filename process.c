#include "ft_ls.h"
#include "libft/libft.h"

bool	get_xattr(char *dir, char *file)
{
    bool	has_xa;
    char 	*path;

    path = join_slash(dir, file);
#ifdef linux
    if(listxattr(path, NULL, 0) > 0)	//!!\\ check buffer size !!
#else
    	if(listxattr(path, NULL, 0, 0) > 0)	//!!\\ check buffer size !!
#endif
	    has_xa = true;
    	else
	    has_xa = false;
    ft_memdel((void**)&path);
    return(has_xa);
}

t_stat	*get_file_stat(char *directory, char *file)
{
    t_stat	*file_stat;
    char 	*path;
    //		char	*error_str;

    file_stat = NULL;
    path = NULL;
    if ((file_stat = (t_stat*)malloc(sizeof(*file_stat))) == NULL)
	print_malloc_error();
    if (directory != NULL)
    {
	path = join_slash(directory, file);
    }
    else
    {
	path = ft_strdup(file);
    }
    if (stat(path, file_stat) != 0)
    {
	print_error_access(strerror(errno), path);
	return(NULL);
    }
    ft_memdel((void**)&path);
    return(file_stat);
}

#define CONTENT (t_file_infos*)(*file_lst).content
#define FILE_MODE (*(*CONTENT).stat).st_mode
#define FILE_NAME (*CONTENT).name
#define FILE_NAME_ISNT(name) ft_strcmp(FILE_NAME, name)

void recursive(t_list **dirlst, t_list *file_lst, char *path)
{
    char    *file_path = NULL;

    if (flag(R))
    {
	//Check all files
	while (file_lst != NULL)
	{
	    //If file is a dir
	    if (S_ISDIR(FILE_MODE))
	    {
		//exclude '.' & '..'
		if (FILE_NAME_ISNT(".") != 0 && FILE_NAME_ISNT("..") != 0)
		{
		    file_path = join_slash(path, FILE_NAME);
		    dirlst_add_dir(dirlst, file_path);
		    ft_memdel((void**)&file_path);
		}
	    }
	    file_lst = (*file_lst).next;
	}
    }
}
#undef CONTENT
#undef FILE_TYPE
#undef FILE_NAME
#undef FILE_NAME_ISNT

#define STRUCT_PATH		(*file_info).path
#define STRUCT_NAME   	(*file_info).name
#define STRUCT_NAME_LEN	(*file_info).name_len
#define STRUCT_MODE		(*file_info).mode
#define STRUCT_INODE	(*file_info).inode
#define STRUCT_STAT		(*file_info).stat
#define STRUCT_XATTR	(*file_info).has_xattr
t_file_infos	*get_file_infos(char *directory, char *file)
{
    t_file_infos	*file_info;

    //malloc file info struct
    file_info = (t_file_infos*)ft_memalloc(sizeof(*file_info));

    //Filling
    if (directory != NULL)
    {
	STRUCT_PATH = ft_strdup(directory);
    }
    STRUCT_NAME = ft_strdup(file);
    STRUCT_STAT = get_file_stat(directory, file);
//  STRUCT_INODE = (*STRUCT_STAT).st_ino;
//  STRUCT_MODE = (*STRUCT_STAT).st_mode;
    STRUCT_XATTR = get_xattr(directory, STRUCT_NAME);
    STRUCT_NAME_LEN = ft_strlen(STRUCT_NAME);


    return(file_info);
}
#undef STRUCT_PATH
#undef STRUCT_NAME
#undef STRUCT_NAME_LEN
#undef STRUCT_TYPE
#undef STRUCT_INODE
#undef STRUCT_STAT
#undef STRUCT_XATTR

#define FILE_NAME		(*s_dir).d_name
t_list  *lst_cur_dir(DIR *dir_stream, char *directory)
{
    t_list		*file_list;
    t_list		*file_link;
    t_file_infos	*file_info;
    t_dirent		*s_dir;

    file_list = NULL;
    file_link = NULL;
    file_info = NULL;

    //Read all files in current dir
    while ((s_dir = readdir(dir_stream)) != NULL)
    {
	//Get file info struct
	file_info = get_file_infos(directory, FILE_NAME);

	//create new link containing file info struct
	file_link = ft_lstnew(NULL, sizeof(file_info));
	(*file_link).content = file_info;

	//sort & add to list
	ft_lstsort(&file_list, file_link);
    }
    return (file_list);
}
#undef FILE_NAME

