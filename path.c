
#include "ft_ls.h"

char *path_to_file(char *path)
{
    return(ft_strrchr(path, '/') + 1);
}

char    *path_join(char *dir, char *file)
{
    char        *path;
    size_t      index;

	if (dir == NULL)
		return(ft_strdup(file));
    index = 0;
    path = ft_strnew(1 + ft_strlen(dir) + ft_strlen(file));
    ft_strcpy(path + index, dir);
    index += ft_strlen(dir);
    if (*(dir + ft_strlen(dir) - 1) != '/')
    {
        ft_strcpy(path + index, "/");
        index += 1;
    }
    ft_strcpy(path + index, file);
    return(path);
}

