#include <stdio.h>
#include "../libft.h"

void	*ft_memdup(const void *src, int size)
{
		char *dst;

		dst = NULL;
		if ((dst = (char *)malloc(sizeof(*dst) * 666)) == NULL)
				return(NULL);
		while (--size >= 0)
				*((char *)dst + size) = *((char *)src + size);
		return(dst);
}

int main(void)
{
		char *src;
		char *dst;

		src = ft_strdup("qwerty");
		dst = (char *)ft_memdup(src, ft_strlen(src));
		printf("dst = %s\n", dst);
		return(0);
}
