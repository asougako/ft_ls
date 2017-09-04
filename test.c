#include "ft_ls.h"


int main(void)
{
		int var1 = 1;
		int var2 = 2;
		int var3 = 3;
		int var4 = 4;
		int var5 = 5;
		int var6 = 6;

		int *ptr1;
		int *ptr2;
		int *ptr3;
		int *ptr4;
		int *ptr5;
		int *ptr6;

		ptr1 = &var1;
		ptr2 = &var2;
		ptr3 = &var3;
		ptr4 = &var4;
		ptr5 = &var5;
		ptr6 = &var6;

		t_list *lst = NULL;
		t_list *link = NULL;


		link = ft_lstnew(ptr1, sizeof(int*));
		ft_lstadd_tail(&lst, link);
		link = ft_lstnew(ptr2, sizeof(int*));
		ft_lstadd_tail(&lst, link);
		link = ft_lstnew(ptr3, sizeof(int*));
		ft_lstadd_tail(&lst, link);
		link = ft_lstnew(ptr4, sizeof(int*));
		ft_lstadd_tail(&lst, link);
		link = ft_lstnew(ptr5, sizeof(int*));
		ft_lstadd_tail(&lst, link);
		link = ft_lstnew(ptr6, sizeof(int*));
		ft_lstadd_tail(&lst, link);


		printf("ptr1 = %p\n", ptr1);
		printf("var1 = %p\n", &var1);
		printf("ptr2 = %p\n", ptr2);
		printf("var2 = %p\n", &var2);
		printf("ptr3 = %p\n", ptr3);
		printf("var3 = %p\n", &var3);
		printf("ptr4 = %p\n", ptr4);
		printf("var4 = %p\n", &var4);
		printf("ptr5 = %p\n", ptr5);
		printf("var5 = %p\n", &var5);
		printf("ptr6 = %p\n", ptr6);
		printf("var6 = %p\n", &var6);

		link = lst;
		while (link != NULL)
		{
				printf("val		%d\n", (*(int*)(*link).content));
				printf("prev	%p\n", &(link));
				printf("curr	%p\n", (link));
				printf("next	%p\n", ((*link).next));
				printf("next	%p\n", &((*link).next));

				link = (*link).next;
		}
		return(0);
}
