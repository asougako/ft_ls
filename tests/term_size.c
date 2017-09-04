#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	printf("term_size = %d x %d\n", w.ws_row, w.ws_col);
	return(0);
}
