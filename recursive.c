
#include "ft_ls.h"

#define REGISTERED_INODE *(ino_t*)(*tmp).content
int             check_loop(ino_t new_inode, bool reset)
{
    static t_list       *ino_lst;
    t_list              *ino_lnk;
    t_list              *tmp;

    if (reset == RESET)
    {
        //add lst_del();
		ft_lstdel(&ino_lst, inolst_destructor);
        ino_lst = NULL;
    }

    ino_lnk = NULL;
    tmp = ino_lst;
    while (tmp != NULL)
    {
        if (REGISTERED_INODE == new_inode)
        {
            return(LOOP_ERROR);
        }
        tmp = (*tmp).next;
    }
    ino_lnk = ft_lstnew(&new_inode, sizeof(ino_t));
    ft_lstadd(&ino_lst, ino_lnk);
    return(0);
}
#undef REGISTERED_INODE

#define FILE_NAME (*(t_xstat*)(*file_lst).content).name
#define FILE_NAME_ISNT(name) ft_strcmp(FILE_NAME, name)
#define FILE_DIR  (*(t_xstat*)(*file_lst).content).path
#define FILE_MODE (*(*(t_xstat*)(*file_lst).content).stat).st_mode
void    recursive(t_list *file_lst)
{
    char        *path;
    t_stat      fstat;
    int         (*stat_func)(const char *restrict, struct stat *restrict);

    if (OPT(R))
    {
        if (OPT(L))
            stat_func = &stat;
        else
            stat_func = &lstat;

        while (file_lst != NULL)
        {
            if (FILE_NAME_ISNT(".") != 0 && FILE_NAME_ISNT("..") != 0)
            {
                path = path_join(FILE_DIR, FILE_NAME);
                if (stat_func(path, &fstat) != 0)
                {
                    //ft_putendl_fd(str_error_access(strerror(errno), FILE_NAME), 2);
                    print_error_access(strerror(errno), FILE_NAME);
                }
                else if (S_ISDIR(FILE_MODE))
                {
                    if (check_loop(fstat.st_ino, NORESET))
                    {
                        print_error_loop(FILE_NAME);
                    }
                    else
                    {
                        ft_putendl("");
                        ft_putstr(path);
                        ft_putendl(":");
                        read_dir(&path);
                    }
                }
				ft_strdel(&path);
            }
            file_lst = (*file_lst).next;
        }
    }
}
#undef FILE_NAME
#undef FILE_NAME_ISNT
#undef FILE_DIR
#undef FILE_MODE
