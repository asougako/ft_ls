/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:26:49 by asougako          #+#    #+#             */
/*   Updated: 2017/11/30 18:28:03 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "stdio.h"

int	main(int argc, char *argv[])
{
	static size_t char_index;
     int ret;

	 printf("\n");
     ret = 0;
     while ((ret = ft_getopt(argc, argv, "abcdef:@")) != -1)
     {
         printf("ret = %c", ret);
         printf(": %s", ft_optarg);
         printf("\toptopt = %c", ft_optopt);
         printf("\toptind = %d\n", ft_optind);


         if (ret == '?')
             exit(EXIT_FAILURE);
     }

     printf("remaining args = %d(%d-%d)\n", argc - ft_optind, argc, ft_optind);

     int index = ft_optind;
     while (*(argv + index))
     {
         printf("*(argv + %d) = %s\n", index, *(argv + index));
         index++;
     }
     return(0);
}
