

#include "libft.h"
#include <stdio.h>

#define DEC_SEP '.'
#define UNIT '\0'
#define KILO 'K'
#define MEGA 'M'
#define GIGA 'G'
#define TERA 'T'

char *human_readable(char *value);

int main(int argc, char **argv)
{
		int index = 1;
		while (index < argc)
		{
				printf("%s >>> %s\n", *(argv + index), human_readable(*(argv + index)));
				index++;
		}
		return(0);
}

char *human_readable(char *value)
{
		char	*ret;
		int		ret_index;
		int		val_index;
		int		val_len;

		ret = ft_strnew(5);
		ret_index = 0;
		val_index = 0;
		val_len = ft_strlen(value);


		while ()
		{
				*(ret + ret_index++) = *(value + val_index++);
		}




		if ((val_len % 3) == 1)
		{
				*(ret + ret_index++) = DEC_SEP;
		}
		*(ret + ret_index++) = *(value + val_index++);

		if (val_len < 3)
		{
				*(ret + ret_index) = 
		}
		if (val_len < 3)
		{

		}



		return(ret);
}
