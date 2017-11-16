
#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft/libft.h"

enum	e_options{
		//num
	opt_0 = 0x0000000000000001ull,
	opt_1 = 0x0000000000000002ull,
	opt_2 = 0x0000000000000004ull,
	opt_3 = 0x0000000000000008ull,
	opt_4 = 0x0000000000000010ull,
	opt_5 = 0x0000000000000020ull,
	opt_6 = 0x0000000000000040ull,
	opt_7 = 0x0000000000000080ull,
	opt_8 = 0x0000000000000100ull,
	opt_9 = 0x0000000000000200ull,
	//alpha maj
	opt_A = 0x0000000000000400ull,
	opt_B = 0x0000000000000800ull,
	opt_C = 0x0000000000001000ull,
	opt_D = 0x0000000000002000ull,
	opt_E = 0x0000000000004000ull,
	opt_F = 0x0000000000008000ull,
	opt_G = 0x0000000000010000ull,
	opt_H = 0x0000000000020000ull,
	opt_I = 0x0000000000040000ull,
	opt_J = 0x0000000000080000ull,
	opt_K = 0x0000000000100000ull,
	opt_L = 0x0000000000200000ull,
	opt_M = 0x0000000000400000ull,
	opt_N = 0x0000000000800000ull,
	opt_O = 0x0000000001000000ull,
	opt_P = 0x0000000002000000ull,
	opt_Q = 0x0000000004000000ull,
	opt_R = 0x0000000008000000ull,
	opt_S = 0x0000000010000000ull,
	opt_T = 0x0000000020000000ull,
	opt_U = 0x0000000040000000ull,
	opt_V = 0x0000000080000000ull,
	opt_W = 0x0000000100000000ull,
	opt_X = 0x0000000200000000ull,
	opt_Y = 0x0000000400000000ull,
	opt_Z = 0x0000000800000000ull,
	//alPha min
	opt_a = 0x0000001000000000ull,
	opt_b = 0x0000002000000000ull,
	opt_c = 0x0000004000000000ull,
	opt_d = 0x0000008000000000ull,
	opt_e = 0x0000010000000000ull,
	opt_f = 0x0000020000000000ull,
	opt_g = 0x0000040000000000ull,
	opt_h = 0x0000080000000000ull,
	opt_i = 0x0000100000000000ull,
	opt_j = 0x0000200000000000ull,
	opt_k = 0x0000400000000000ull,
	opt_l = 0x0000800000000000ull,
	opt_m = 0x0001000000000000ull,
	opt_n = 0x0002000000000000ull,
	opt_o = 0x0004000000000000ull,
	opt_p = 0x0008000000000000ull,
	opt_q = 0x0010000000000000ull,
	opt_r = 0x0020000000000000ull,
	opt_s = 0x0040000000000000ull,
	opt_t = 0x0080000000000000ull,
	opt_u = 0x0100000000000000ull,
	opt_v = 0x0200000000000000ull,
	opt_w = 0x0400000000000000ull,
	opt_x = 0x0800000000000000ull,
	opt_y = 0x1000000000000000ull,
	opt_z = 0x2000000000000000ull,
};

typedef struct  s_sopt
{
	uint64_t    opt;
	t_list      *lopt;
}               t_sopt;

typedef struct	s_loption
{
	char		*name;
	char		*value;
}				t_loption;

t_sopt		ft_getopt(int ac, char **av);
t_sopt		parse_opt(int ac, char **av);
void	av_sort(char **av);
int         arg_comp(const char *arg1, const char *arg2);
void        parse_short_opt(char *arg, uint64_t *opt);
void        parse_long_opt(char **arg, t_list **lopt);
void        clear_opt(int ac, char **av);
void        ft_print_short_options(uint64_t params);
void        ft_print_long_options(t_list *opt_lst);

#endif
