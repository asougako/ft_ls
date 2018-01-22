#include "libft.h"

char    *ft_lowstr(char *src)
{
        int index;

        index = 0;
        while (*(src + index) != 0)
        {
                *(src + index) = ft_tolower(*(src + index));
                index++;
        }
        return(src);
}

