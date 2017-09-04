#include "libft.h"
#include "ft_getopt.h"
#include <stdio.h>

int         main(int argc, char *argv[])
{
        uint64_t    opt;
        t_list      *lopt;

        lopt = NULL;
        opt = ft_getopt(argc, argv, &lopt);
        ft_putstr("Short options:\n");
        ft_print_short_options(opt);
        ft_putstr("\nLong options:\n");
        ft_print_long_options(lopt);
        ft_putchar('\n');
        ft_putendl("Remainings args:");
        while (*argv != NULL)
        {
                ft_putchar('\t');
                ft_putendl(*argv++);
        }

        return(0);
}
