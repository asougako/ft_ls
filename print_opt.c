

#include "ft_ls.h"
#include "libft/libft.h"

#define CONTENT (*(t_file_infos*)(*l_file_info).content)
#define FILE_NAME (CONTENT).name
#define FILE_NAME_ISNT(name) ft_strcmp(FILE_NAME, name)
#define file_print CONTENT.printable

void    process_printable(t_list *l_file_info)
{
                printable_default(l_file_info);
                (sopt(NULL).opt & opt_A) ? printable_opt_A(l_file_info): 0;
                (sopt(NULL).opt & opt_B) ? printable_opt_B(l_file_info): 0;
                (sopt(NULL).opt & opt_a) ? printable_opt_a(l_file_info): 0;

}

//do not list implied entries starting with .
void    printable_default(t_list *l_file_info)
{
        while(l_file_info != NULL)
        {
                if (*(FILE_NAME + 0) == '.')
                        CONTENT.printable = false;
                else
                        CONTENT.printable = true;
                l_file_info = (*l_file_info).next;
        }
}

//do not ignore entries starting with .
void    printable_opt_a(t_list *l_file_info)
{
        while(l_file_info != NULL)
        {
                file_print = true;
                l_file_info = (*l_file_info).next;
        }
}

//do not list implied . and ..
void    printable_opt_A(t_list *l_file_info)
{
        while(l_file_info != NULL)
        {
                if (ft_strcmp(FILE_NAME, ".") == 0 || ft_strcmp(FILE_NAME, "..") == 0)
                        file_print = false;
                else
                        file_print = true;
                l_file_info = (*l_file_info).next;
        }
}

//do not list implied entries ending with ~
void    printable_opt_B(t_list *l_file_info)
{
        while(l_file_info != NULL)
        {
                if (*(FILE_NAME + (ft_strlen(FILE_NAME) - 1)) == '~')
                {
                        file_print = false;
                }
                l_file_info = (*l_file_info).next;
        }
}

#undef FILE_NAME
#undef FILE_NAME_ISNT
#undef CONTENT
