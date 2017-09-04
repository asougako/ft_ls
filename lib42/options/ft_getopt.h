
#ifndef FT_GETOPT_H
# define FT_GETOPT_H

uint64_t    ft_getopt(int ac, char **av, t_list **lopt);
int         av_sort(char **av);
int         arg_comp(const char *arg1, const char *arg2);
uint64_t    parse_opt(int ac, char **av, t_list **lopt);
void        parse_short_opt(char *arg, uint64_t *opt);
void        parse_long_opt(char **arg, t_list **lopt);
void        clear_opt(int ac, char **av);
void        ft_print_short_options(uint64_t params);
void        ft_print_long_options(t_list *opt_lst);

enum	e_options{
		//num
	opt_0 = 0x0000000000000001,
	opt_1 = 0x0000000000000002,
	opt_2 = 0x0000000000000004,
	opt_3 = 0x0000000000000008,
	opt_4 = 0x0000000000000010,
	opt_5 = 0x0000000000000020,
	opt_6 = 0x0000000000000040,
	opt_7 = 0x0000000000000080,
	opt_8 = 0x0000000000000100,
	opt_9 = 0x0000000000000200,
	//alpha maj
	opt_A = 0x0000000000000400,
	opt_B = 0x0000000000000800,
	opt_C = 0x0000000000001000,
	opt_D = 0x0000000000002000,
	opt_E = 0x0000000000004000,
	opt_F = 0x0000000000008000,
	opt_G = 0x0000000000010000,
	opt_H = 0x0000000000020000,
	opt_I = 0x0000000000040000,
	opt_J = 0x0000000000080000,
	opt_K = 0x0000000000100000,
	opt_L = 0x0000000000200000,
	opt_M = 0x0000000000400000,
	opt_N = 0x0000000000800000,
	opt_O = 0x0000000001000000,
	opt_P = 0x0000000002000000,
	opt_Q = 0x0000000004000000,
	opt_R = 0x0000000008000000,
	opt_S = 0x0000000010000000,
	opt_T = 0x0000000020000000,
	opt_U = 0x0000000040000000,
	opt_V = 0x0000000080000000,
	opt_W = 0x0000000100000000,
	opt_X = 0x0000000200000000,
	opt_Y = 0x0000000400000000,
	opt_Z = 0x0000000800000000,
	//alPha min
	opt_a = 0x0000001000000000,
	opt_b = 0x0000002000000000,
	opt_c = 0x0000004000000000,
	opt_d = 0x0000008000000000,
	opt_e = 0x0000010000000000,
	opt_f = 0x0000020000000000,
	opt_g = 0x0000040000000000,
	opt_h = 0x0000080000000000,
	opt_i = 0x0000100000000000,
	opt_j = 0x0000200000000000,
	opt_k = 0x0000400000000000,
	opt_l = 0x0000800000000000,
	opt_m = 0x0001000000000000,
	opt_n = 0x0002000000000000,
	opt_o = 0x0004000000000000,
	opt_p = 0x0008000000000000,
	opt_q = 0x0010000000000000,
	opt_r = 0x0020000000000000,
	opt_s = 0x0040000000000000,
	opt_t = 0x0080000000000000,
	opt_u = 0x0100000000000000,
	opt_v = 0x0200000000000000,
	opt_w = 0x0400000000000000,
	opt_x = 0x0800000000000000,
	opt_y = 0x1000000000000000,
	opt_z = 0x2000000000000000,
};

typedef struct	s_option
{
	char		*name;
	char		*value;
}				t_option;

#endif
