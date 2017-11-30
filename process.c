
#include "ft_ls.h"

void    process_args(char **argv, int argc)
{
    process_files(argv + 0);
    process_dirs(argv + 0, argc);
}
