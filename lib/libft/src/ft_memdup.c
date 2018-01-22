#include "../libft.h"

void	*ft_memdup(const void *src, int size)
{
		unsigned char *dst;

		dst = NULL;
		if ((dst = (unsigned char*)malloc(sizeof(*dst) * size)) == NULL)
				return(NULL);
		while (--size >= 0)
				*((unsigned char *)dst + size) = *((unsigned char *)src + size);
		return(dst);
}
