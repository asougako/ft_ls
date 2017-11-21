#include "ft_ls.h"

static char    *cust_strdup(char *src)
{
    char    *dst;
    char    *tmp_dst;

    dst = NULL;
    dst = ft_strnew(ft_strlen(src));
    tmp_dst = dst;
    while(*src != '\0')
    {
        if (ft_isalnum(*src))
        {
            *tmp_dst = *src;
            tmp_dst++;
        }
        src++;
    }
    return(dst);
}

static int     rev_alpha_strcmp(char *s1, char *s2)
{
    uint32_t    index;
    int32_t     c1;
    int32_t     c2;

    c1 = 0;
    c2 = 0;
    index = 0;
    while (*(s1 + index) != '\0' || *(s2 + index) != '\0')
    {
        c1 = *(s1 + index);
        c2 = *(s2 + index);
        if (ft_isupper(c1))
            c1 += 'a' - 'A';
        else if (ft_islower(c1))
            c1 -= 'a' - 'A';
        if (ft_isupper(c2))
            c2 += 'a' - 'A';
        else if (ft_islower(c2))
            c2 -= 'a' - 'A';
        if (c1 != c2)
            break;
        index++;
    }
    return((int)(c1 - c2));
}

int64_t				rev_name_sort(void *content1, void *content2)
{
    return(-name_sort(content1, content2));
}

#define file_name(INDEX) ((*(t_xstat*)content ## INDEX )).name
int64_t				name_sort(void *content1, void *content2)
{
	int compare;

	compare = 0;
	compare = ft_strcmp(file_name(1), file_name(2));
	return (compare);
}
int				name_sort_linux(void *content1, void *content2)
{
    int compare = 0;
    char *low_name1;
    char *low_name2;

    low_name1 = cust_strdup(file_name(1));
    low_name2 = cust_strdup(file_name(2));
    ft_lowstr(low_name1);
    ft_lowstr(low_name2);
    compare = ft_strcmp(low_name1, low_name2);
    if (compare == 0)
    {
	ft_strdel(&low_name1);
	ft_strdel(&low_name2);
        low_name1 = cust_strdup(file_name(1));
        low_name2 = cust_strdup(file_name(2));
        compare = rev_alpha_strcmp(low_name1, low_name2);
    }
    if (compare == 0)
    {
	ft_strdel(&low_name1);
	ft_strdel(&low_name2);
        low_name1 = ft_strdup(file_name(1));
        low_name2 = ft_strdup(file_name(2));
        if (ft_isalnum(*(low_name1 + 0)) == 1)
            compare = -1;
        else if (ft_isalnum(*(low_name2 + 0)) == 1)
            compare = 1;
        else
            compare = ft_strcmp(low_name1, low_name2);
    }
    ft_strdel(&low_name1);
    ft_strdel(&low_name2);
    return(compare);
}
#undef file_name
