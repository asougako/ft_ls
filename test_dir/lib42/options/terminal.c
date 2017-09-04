#include "../libft/libft.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_term_info{
	uint32_t	lines;
	uint32_t	columns;
}				t_term_info;

int main(void)
{
		printf("row = %d\ncol = %d\n", w.ws_row, w.ws_col);

}

t_term_info	get_term_size(void)
{
		struct		winsize w;
		t_term_info	term_size;

		ioctl(STDOUT_FILENO, TIOCGWINZ, &w);
		term_size.lines = w.ws_row;
		s_term_info.columns = w.ws_col;
		return();
}

