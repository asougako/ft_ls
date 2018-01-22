/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:51:12 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 18:15:23 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return a new ditionary holding paired words(char *)
**	and definitions(any type).
**	Format must contain flags indicating each definitions types.
*/

#include "./libft.h"

/*
**	Return the flag index.
*/

static int		get_flag_index(char *flag)
{
	int			index;
	static char	*flag_str[] = {	"vo", "sc", "ss", "si", "sl", "sq",\
								"uc", "us", "ui", "ul", "uq",\
								"sd", "dd", "ld",\
								"pc", "ps", "pi", "pl", "pq", "pv", ""};

	index = 0;
	while (*flag_str[index] != '\0')
	{
		if (ft_strstr(flag_str[index], flag) != NULL)
			return (index);
		index++;
	}
	return (0);
}

/*
**	Separate next flag in format, return it's index.
*/

static	int		get_next_flag(char *format)
{
	char	*next_perc;
	char	*next_next_perc;
	char	*flag;

	if ((next_perc = ft_strchr(format, '%')) == NULL || *(next_perc + 1) == 0)
		return (0);
	if ((next_next_perc = ft_strchr(next_perc + 1, '%')) == NULL)
	{
		flag = ft_strdup(next_perc + 1);
		format = ft_memset(format, '\0', 1);
	}
	else
	{
		flag = ft_strndup(next_perc + 1, next_next_perc - (next_perc + 1));
		format = ft_strcpy(format, next_next_perc);
	}
	return (get_flag_index(flag));
}

/*
**	Create a new dict list with type field filled.
*/

static t_list	*get_types(char *format, t_list **dict)
{
	t_list			*lst_link;
	t_dictionary	*dict_content;
	char			*format_cpy;
	int				flag;

	format_cpy = ft_strdup(format);
	while ((flag = get_next_flag(format_cpy)) != 0)
	{
		if (!(dict_content = (t_dictionary*)malloc(sizeof(*dict_content))))
			return (NULL);
		(*dict_content).word = NULL;
		(*dict_content).definition.uq = 0ULL;
		(*dict_content).type = flag;
		(*dict_content).next = NULL;
		lst_link = ft_lstnew(dict_content, sizeof(*dict_content));
		ft_lstadd_tail(dict, lst_link);
	}
	ft_strdel(&format_cpy);
	return (*dict);
}

/*
**	Retrieve variadics arguments with the right type.
*/

#define TYP (*(t_dictionary*)(*dict).content).type
#define DEF (*(t_dictionary*)(*dict).content).definition
#define GET_ARG(DT,SF,CT,AT) TYP == DT ? DEF.SF = (CT)va_arg(ap, AT) : 0

static void		get_args(va_list ap, t_list *dict)
{
	while (dict != NULL)
	{
		(*(t_dictionary*)(*dict).content).word = va_arg(ap, char *);
		GET_ARG(d_char, sc, char, int);
		GET_ARG(d_short, ss, short, int);
		GET_ARG(d_int, si, int, int);
		GET_ARG(d_long, sl, long, long);
		GET_ARG(d_long_long, sq, long long, long long);
		GET_ARG(d_u_char, uc, unsigned char, unsigned int);
		GET_ARG(d_u_short, us, unsigned short, unsigned int);
		GET_ARG(d_u_int, ui, unsigned int, unsigned int);
		GET_ARG(d_u_long, ul, unsigned long, unsigned long);
		GET_ARG(d_u_long_long, uq, unsigned long long, unsigned long long);
		GET_ARG(d_float, sd, float, double);
		GET_ARG(d_double, dd, double, double);
		GET_ARG(d_long_double, ld, long double, long double);
		GET_ARG(d_char_ptr, pc, char *, char *);
		GET_ARG(d_short_ptr, ps, short *, short *);
		GET_ARG(d_int_ptr, pi, int *, int *);
		GET_ARG(d_long_ptr, pl, long *, long *);
		GET_ARG(d_long_long_ptr, pq, long long *, long long *);
		GET_ARG(d_void_ptr, pv, void *, void *);
		dict = (*dict).next;
	}
	return;
}

t_list			*ft_dict_new(char *format, ...)
{
	t_list	*dict;
	va_list	ap;

	va_start(ap, format);
	dict = NULL;
	dict = get_types(format, &dict);
	get_args(ap, dict);
	va_end(ap);
	return (dict);
}
