/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:03:47 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 19:18:10 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_dict_print(t_list *dict)
{
	unsigned int	index;

	index = 0;
	while (dict != NULL)
	{
		if ((*(t_dictionary*)(*dict).content).type == 1)
			printf("%d - \"%s\": %c (char)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.sc);
		else if ((*(t_dictionary*)(*dict).content).type == 2)
			printf("%d - \"%s\": %hd (short)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.ss);
		else if ((*(t_dictionary*)(*dict).content).type == 3)
			printf("%d - \"%s\": %d (int)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.si);
		else if ((*(t_dictionary*)(*dict).content).type == 4)
			printf("%d - \"%s\": %ld (long)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.sl);
		else if ((*(t_dictionary*)(*dict).content).type == 5)
			printf("%d - \"%s\": %lld (long long)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.sq);
		else if ((*(t_dictionary*)(*dict).content).type == 6)
			printf("%d - \"%s\": %hhu (unsigned char)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.uc);
		else if ((*(t_dictionary*)(*dict).content).type == 7)
			printf("%d - \"%s\": %hu (unsigned short)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.us);
		else if ((*(t_dictionary*)(*dict).content).type == 8)
			printf("%d - \"%s\": %u (unsigned int)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.ui);
		else if ((*(t_dictionary*)(*dict).content).type == 9)
			printf("%d - \"%s\": %lu (unsigned long)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.ul);
		else if ((*(t_dictionary*)(*dict).content).type == 10)
			printf("%d - \"%s\": %llu (unsigned long long)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.uq);
		else if ((*(t_dictionary*)(*dict).content).type == 11)
			printf("%d - \"%s\": %f (float)\n",\
					index,
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.sd);
		else if ((*(t_dictionary*)(*dict).content).type == 12)
			printf("%d - \"%s\": %f (double)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.dd);
		else if ((*(t_dictionary*)(*dict).content).type == 13)
			printf("%d - \"%s\": %Lf (long double)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.ld);
		else if ((*(t_dictionary*)(*dict).content).type == 14)
			printf("%d - \"%s\": %s (char *)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.pc);
		else if ((*(t_dictionary*)(*dict).content).type == 15)
			printf("%d - \"%s\": %p (short *)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.ps);
		else if ((*(t_dictionary*)(*dict).content).type == 16)
			printf("%d - \"%s\": %p (int *)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.pi);
		else if ((*(t_dictionary*)(*dict).content).type == 17)
			printf("%d - \"%s\": %p (long *)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.pl);
		else if ((*(t_dictionary*)(*dict).content).type == 18)
			printf("%d - \"%s\": %p (long long *)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.pq);
		else if ((*(t_dictionary*)(*dict).content).type == 19)
			printf("%d - \"%s\": %p (void *)\n",\
					index,\
					(*(t_dictionary*)(*dict).content).word,\
					(*(t_dictionary*)(*dict).content).definition.pv);
		else
			printf("TYPE ERROR\n");
		dict = (*dict).next;
		index++;
	}
}
