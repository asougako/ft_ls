#include "ft_ls.h"

void test(void)
{
		printf("TESTS PRELIMINAIRES...\n");
		printf("DIRENT TESTS:\n");
#ifdef _DIRENT_HAVE_D_NAMLEN
		printf("\tHas NAMELEN\n");
#else
		printf("\tHas NOT NAMELEN\n");
#endif
#ifdef _DIRENT_HAVE_D_RECLEN
		printf("\tHas RECLEN\n");
#else
		printf("\tHas NOT RECLEN\n");
#endif
#ifdef _DIRENT_HAVE_D_OFF
		printf("\tHas OFF\n");
#else
		printf("\tHas NOT OFF\n");
#endif
#ifdef _DIRENT_HAVE_D_TYPE
		printf("\tHas TYPE\n");
#else
		printf("\tHas NOT TYPE\n");
#endif

		printf("ERRNO TEST\n");
#ifdef __USE_GNU
		printf("\tUse GNU\n");
		printf("%s\n", program_invocation_name);
#else
		printf("\tDONT use GNU\n");
#endif
		printf("UNISTD_TEST\t");
#ifdef _POSIX_ADVISORY_INFO
		printf("\t_POSIX_ADVISORY_INFO = %d\n", _POSIX_ADVISORY_INFO);
#else
		printf("\t_POSIX_ADVISORY_INFO NOT DEFINED\n");
#endif
}
