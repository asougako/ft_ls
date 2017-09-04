
#include <stdio.h>
#include "libft.h"

#define TAB_LEN 6

int low_i = 0;
int hig_i = 0;

void	print_tab(int *tab)
{
	for (int i = 0; i < TAB_LEN; i++)
		printf("*(strtab + %d) = %d\n", i, *(tab + i));
}

int		sort_by_len(int s1, int s2)
{
	return(s1 - s2);
}

void	swap(int *s1, int *s2)
{
	int tmp;
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		part(int *tab, int first, int last, int pivot)
{
	int		i;
	int		j;

	//printf("PART\n");
	printf("1swap(tab[pivot=%d]=%d, tab[last=%d]%d)\n", pivot, tab[pivot], last, tab[last]);
	swap(&tab[pivot], &tab[last]);
	j = first;
	for(i = first; i < last; i++)
	{
		printf("if tab[i=%d]=%d <= tab[las=%d]=%d\n", i, tab[i], last, tab[last]);
		if(tab[i] <= tab[last])
		{
			printf("2swap(tab[i=%d]=%d, tab[j=%d]%d)\n", i, tab[i], j, tab[j]);
			swap(&tab[i], &tab[j]);
			j++;
		}
	}
	printf("3swap(tab[last=%d]=%d, tab[j=%d]%d)\n", last, tab[last], j, tab[j]);
	swap(&tab[last], &tab[j]);
	return(j);
}

void	ft_qsort(int *tab, int first, int last)
{
	int		pivot;

	if (first < last)
	{
		pivot = first;
		print_tab(tab);
		printf("PARTITION\n");
		pivot = part(tab, first, last, pivot);
		print_tab(tab);
		ft_putendl("");
		low_i++;
		printf("%d QSORT LOWER(tab, firts=%d, last=%d)\n", low_i, first, pivot - 1);
		ft_qsort(tab, first, pivot - 1);	//qsort lower  half
		hig_i++;
		printf("%d QSORT HIGHER(tab, firts=%d, last=%d)\n", hig_i, pivot + 1, last);
		ft_qsort(tab, pivot + 1, last);		//qsort higher half
	}
}

int		main(void)
{
	int tab[TAB_LEN] = {1,2,4,3,6,5};


	ft_putendl("");
	printf("QSORT(tab, firts=0, last=%d)\n", TAB_LEN - 1);
	ft_qsort(tab, 0, TAB_LEN -1);

}
#undef TAB_LEN
