
#include "libft.h"

void		ft_qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

static void	ft_swap(void *p1, void *p2, size_t size)
{
		if(size == 1)
		{
				*((uint8_t*)p1) = (uint8_t)(*((uint8_t*)p1) ^ *((uint8_t*)p2));
				*((uint8_t*)p2) = (uint8_t)(*((uint8_t*)p2) ^ *((uint8_t*)p1));
				*((uint8_t*)p1) = (uint8_t)(*((uint8_t*)p1) ^ *((uint8_t*)p2));
		}
		else if(size == 2)
		{
				*((uint16_t*)p1) = (uint16_t)(*((uint16_t*)p1) ^ *((uint16_t*)p2));
				*((uint16_t*)p2) = (uint16_t)(*((uint16_t*)p2) ^ *((uint16_t*)p1));
				*((uint16_t*)p1) = (uint16_t)(*((uint16_t*)p1) ^ *((uint16_t*)p2));
		}
		else if(size == 4)
		{
				*((uint32_t*)p1) = (uint32_t)(*((uint32_t*)p1) ^ *((uint32_t*)p2));
				*((uint32_t*)p2) = (uint32_t)(*((uint32_t*)p2) ^ *((uint32_t*)p1));
				*((uint32_t*)p1) = (uint32_t)(*((uint32_t*)p1) ^ *((uint32_t*)p2));
		}
		else if(size == 8)
		{
				*((uint64_t*)p1) = (uint64_t)(*((uint64_t*)p1) ^ *((uint64_t*)p2));
				*((uint64_t*)p2) = (uint64_t)(*((uint64_t*)p2) ^ *((uint64_t*)p1));
				*((uint64_t*)p1) = (uint64_t)(*((uint64_t*)p1) ^ *((uint64_t*)p2));
		}
}

#define FST	((uint8_t*)base + 0)
#define LST	((uint8_t*)base + ((nmemb - 1) * size))
#define PIV	((uint8_t*)base + (pivot * size))
#define TAB(INDEX)((uint8_t*)base + (INDEX * size))

static int	part(void *base, size_t nmemb, size_t pivot, size_t size, int (*compare)(const void*, const void*))
{
		size_t i;
		size_t j;

		i = 0;
		j = 0;
		ft_swap(PIV, LST, size);
		while (i < nmemb - 1)
		{
				if (compare(TAB(i), LST) < 0)
				{
						if (i != j)
								ft_swap(TAB(i), TAB(j), size);
						j++;
				}
				i++;
		}
		if (j < (nmemb - 1))
				ft_swap(LST, TAB(j), size);
		return(j);
}

#undef FST
#undef LST
#undef PIV
#undef TAB

void	ft_qsort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *))
{
		size_t	pivot;

		if (nmemb > 1)
		{
				pivot = 0;
				pivot = part(base, nmemb, pivot, size, compare);
				ft_qsort(base, pivot, size, compare);
				ft_qsort((void*)((uint8_t*)base + ((pivot + 1) * size)), (nmemb - (pivot + 1)), size,compare);
		}
}

