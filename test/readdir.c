
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 0x1000
#define PATH *(argv + 1)
#define FILE_NAME (*dirs).d_name
#define FILE_TYPE (*dirs).d_type
int main(int argc, char **argv)
{
	DIR		*dirp = NULL;
	struct dirent	*dirs = NULL;
	size_t		size = 0;
	char		*buff;
	struct stat	sb;

	buff = (char*)malloc(sizeof(*buff) * BUFF_SIZE);

    	if (argc != 2)
    	{
    	    printf("Need only 1 arg!\n");
	    return(-1);
	}

	dirp = opendir(PATH);
	if (dirp == NULL)
	{
	    printf("Can't open %s: %s\n", PATH, strerror(errno));
	    perror(PATH);
	    return(-1);
	}
	while ((dirs = readdir(dirp)) != NULL)
	{
		stat(FILE_NAME, &sb);
		printf("\n%s >> %llo >> %d\n", FILE_NAME, sb.st_mode & S_IFMT, S_ISDIR(sb.st_mode));
		switch(FILE_TYPE)
		{
			case 4:
			printf("d ");
			break;
			case 8:
			printf("  ");
			break;
			case 10:
			printf("l ");
			break;
			default:
			printf("  ");
			break;

		}
		if (FILE_TYPE == 10)
		{
			size = readlink(FILE_NAME, buff, BUFF_SIZE);
			//printf("readlink reads %d bytes.\n", size);
			printf("%s", FILE_NAME);
			printf(" -> %s\n", buff);
		}
		else
		{
			printf("%s\n", FILE_NAME);
		}
	}
	printf("\nerrno = %d: %s\n", errno, strerror(errno));


    	return(0);
}
