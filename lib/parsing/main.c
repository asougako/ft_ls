#include "ft_getopt.h"
#include "libft.h"
#include <stdio.h>

int         main(int argc, char *argv[])
{
        uint64_t    opt;
        t_list      *lopt;

        lopt = NULL;
        opt = ft_getopt(argc, argv, &lopt);

        printf("Short options:\n");
        ft_print_short_options(opt);

        printf("\nLong options:\n");
        ft_print_long_options(lopt);

        printf("\nRemainings args:\n");
        while (*argv != NULL)
				printf("\t%s\n", *argv++);

        return(0);
}
