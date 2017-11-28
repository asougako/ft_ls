
#include "ft_ls.h"

void    process_args(char **argv, int argc)
{
    process_files(argv + 1);
    process_dirs(argv + 1, argc);
}
