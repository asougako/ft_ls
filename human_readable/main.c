
#include <stdio.h>
#include "ft_human_readable.h"

int main(int argc, char **argv)
{
	int index = 1;
	while (index < argc)
	{
		printf("%s >>> %s\n", *(argv + index), ft_human_readable(*(argv + index)));
		index++;
	}
	return(0);
}
