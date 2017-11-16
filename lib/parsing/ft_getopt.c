
#include "ft_getopt.h"

t_sopt	ft_getopt(int ac, char **av)
{
    uint64_t	opt;
    t_list		**lopt;
    t_sopt		sopt;

    av_sort(av);
    sopt = parse_opt(ac, av);
    clear_opt(ac, av);
    return(sopt);
}

#define CURR_ARG *(av + index)
#define PREV_ARG *((av + index) - 1)
void	av_sort(char **av)
{
    int		index;
    uint8_t	again;

    again = 1;
    while (again == 1)
    {
	index = 1;
	again = 0;
	while (CURR_ARG != NULL)
	{
	    if (arg_comp(PREV_ARG, CURR_ARG) > 0)
	    {
		PREV_ARG = (char*)((uint64_t)PREV_ARG ^ (uint64_t)CURR_ARG);
		CURR_ARG = (char*)((uint64_t)CURR_ARG ^ (uint64_t)PREV_ARG);
		PREV_ARG = (char*)((uint64_t)PREV_ARG ^ (uint64_t)CURR_ARG);
		again = 1;
	    }
	    index++;
	}
    }
}
#undef CURR_ARG
#undef PREV_ARG

#define PREV_ARG(INDEX) *(prev_arg + INDEX)
#define CURR_ARG(INDEX) *(curr_arg + INDEX)
int	arg_comp(const char *prev_arg, const char *curr_arg)
{
    if (PREV_ARG(0) != '-')							//prev non opt
	return(0);									//dont swap

    if (PREV_ARG(0) == '-' && PREV_ARG(1) == 0x00)	//prev fake opt
	return(0);									//dont swap

    if (PREV_ARG(0) == '-' && PREV_ARG(1) != 0x00)			//prev opt
    {
	if (CURR_ARG(0) != '-')								//curr not opt
	    return(1);										//swap
	if (CURR_ARG(0) == '-' && CURR_ARG(1) == 0x00)		//curr fake opt
	    return(1);										//swap
    }
    return(0);
}
#undef CURR_ARG
#undef PREV_ARG


/*	CLEAR	*/
#define CURR_ARG *(av + ac)
void	clear_opt(int ac, char **av)
{
    ac--;
    while (*(*(av + ac) + 0) == '-' && *(*(av + ac) + 1) != '\0')
    {
	CURR_ARG = NULL;
	ac--;
    }
}
#undef CURR_ARG
