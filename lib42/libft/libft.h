/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:21:17 by asougako          #+#    #+#             */
/*   Updated: 2017/06/02 12:55:41 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include "get_next_line.h"

# ifdef __unix__
#  define int16_t   short
#  define int64_t   long
#  define intmax_t  int64_t
#  define uint8_t   unsigned char
#  define uint16_t  unsigned short
#  define uint32_t  unsigned int
#  define uint64_t  unsigned long
#  define uintmax_t uint64_t
# endif

enum				e_types{
	d_void,
	d_char,
	d_short,
	d_int,
	d_long,
	d_long_long,
	d_u_char,
	d_u_short,
	d_u_int,
	d_u_long,
	d_u_long_long,
	d_float,
	d_double,
	d_long_double,
	d_char_ptr,
	d_short_ptr,
	d_int_ptr,
	d_long_ptr,
	d_long_long_ptr,
	d_void_ptr,
	d_func_ptr
};

typedef union		u_definition{
	char				sc;
	short				ss;
	int					si;
	long				sl;
	long long			sq;
	unsigned char		uc;
	unsigned short		us;
	unsigned int		ui;
	unsigned long		ul;
	unsigned long long	uq;
	float				sd;
	double				dd;
	long double			ld;
	char				*pc;
	short				*ps;
	int					*pi;
	long				*pl;
	long long			*pq;
	void				*pv;
}					t_definition;

typedef struct		s_dictionary{
	char				*word;
	t_definition		definition;
	enum e_types		type;
	struct s_dictionary	*next;
}					t_dictionary;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Base functions.
*/
void				*ft_memset(void *src, int filler, size_t len);
void				ft_bzero(void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *src, int c, size_t len);
int					ft_memcmp(const void *src1, const void *src2, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hay, const char *nee, size_t size);
int					ft_strcmp(const char *dst, const char *src);
int					ft_strncmp(const char *dst, const char *src, size_t n);
int					ft_atoi(const char *alpha);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int64_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnstr(const char *str, size_t size);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Bonus functions.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Extra functions.
*/
int					ft_isspace(int c);
size_t				ft_intlen(uint64_t u_i, size_t base);
char				*ft_uitoa(uint64_t u_n);
char				*ft_itoabase(uint64_t u_n, const char *base);
char				**ft_strtab_new(void);
char				**ft_strtab_add(char **src, char *str);
char				**ft_strtab_dup(char **src);
size_t				ft_strtab_len(char **src);
void				ft_lstadd_tail(t_list **alst, t_list *new);
char				*ft_strndup(const char *src, size_t size);
int					ft_lstdelif(t_list **list, void *match,\
						int(*del)(void*, size_t, void*));
void				*ft_lstchr(t_list **list, void *match,\
						int(*fnc)(void*, size_t, void*));
t_list				*ft_dict_new(char *format, ...);
t_list				*ft_dict_add(t_list *dict_1, t_list *dict_2);
int					ft_dict_del(t_list **dict);
int					ft_dict_wdel(t_list **dict, char *name);
int					ft_dict_idel(t_list **dict, unsigned int ref);
t_definition		*ft_dict_wchr(t_list *dict, char *name);
t_definition		*ft_dict_ichr(t_list *dict, int ref);
void				ft_dict_print(t_list *dict);
void				ft_print_memory(const void *addr, size_t size);
char				*ft_lowstr(char *src);
char				*ft_uppstr(char *src);


#endif
