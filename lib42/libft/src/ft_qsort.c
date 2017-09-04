
#include "libft.h"
#include <stdio.h>

void		ft_qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
static void	ft_swap(void *p1, void *p2, size_t size);

int		cmpstringp(const void *p1, const void *p2)
{
		return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int		cmpint(const void *p1, const void *p2)
{
		return(*((int *)p1) - *((int *)p2));
}

int		cmpchar(const void *p1, const void *p2)
{
		return(*((char*)p1) - *((char*)p2));
}

int		main(int argc, char *argv[])
{
		/*	int[]	*/
		int j;

		int			*int_tab;
		int_tab = (int*)malloc(10 * sizeof(*int_tab));
		*(int_tab + 0) = 9;
		*(int_tab + 1) = 8;
		*(int_tab + 2) = 7;
		*(int_tab + 3) = 6;
		*(int_tab + 4) = 5;
		*(int_tab + 5) = 4;
		*(int_tab + 6) = 3;
		*(int_tab + 7) = 2;
		*(int_tab + 8) = 1;
		*(int_tab + 9) = 0;

		/*	char[]	*/
		char *str;
		str = ft_strdup("qwertyuiop");

		if (argc < 2) {
				fprintf(stderr, "Usage: %s <string>...\n", argv[0]);
				exit(EXIT_FAILURE);
		}
//PRINT
		for (j=0;j<10;j++)
				printf("int_tab[%d] = %d\n", j, *(int_tab + j));
		for (j=0;j<ft_strlen(str);j++)
				printf("str[%d] = %c\n", j, *(str + j));
		for (j=0;j<argc-1;j++)
				printf("strtab[%d] = %s\n", j, *(argv + 1 + j));
//SORT
				ft_qsort(int_tab, 10, sizeof(int), cmpint);
				ft_qsort(str, ft_strlen(str), sizeof(char), cmpchar);
				ft_qsort(&argv[1], argc - 1, sizeof(char *), cmpstringp);
//PRINT
		for (j=0;j<10;j++)
				printf("int_tab[%d] = %d\n", j, *(int_tab + j));
		for (j=0;j<ft_strlen(str);j++)
				printf("str[%d] = %c\n", j, *(str + j));
		for (j=0;j<argc-1;j++)
				printf("strtab[%d] = %s\n", j, *(argv + 1 + j));

		exit(EXIT_SUCCESS);
}

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

#define PREV_PTR (void*)((uint8_t*)base + ((index - 1) * size))
#define CURR_PTR (void*)((uint8_t*)base + (index * size))
void	ft_qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
		int		index;
		int		again;

		again = 1;
		while (again == 1)
		{
				again = 0;
				index = 1;
				while (index < nmemb)
				{
						if ((*compar)(PREV_PTR, CURR_PTR) > 0)
						{
								ft_swap(PREV_PTR, CURR_PTR, size);
								again = 1;
						}
						index++;
				}
		}
}
#undef PREV_PTR
#undef CURR_PTR
