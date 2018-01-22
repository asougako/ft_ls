

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	static size_t char_index;
	int ret;

	ret = 0;
	while ((ret = getopt(argc, argv, "abcdef:@")) != -1)
	{
		printf("ret = %c", ret);
		printf(": %s", optarg);
		printf("\toptopt = %c", optopt);
		printf("\toptind = %d\n", optind);


		if (ret == '?')
			exit(EXIT_FAILURE);
	}

	printf("remaining args = %d(%d-%d)\n", argc - optind, argc, optind);

	int index = optind;
	while (*(argv + index))
	{
		printf("*(argv + %d) = %s\n", index, *(argv + index));
		index++;
	}
	return(0);
}
