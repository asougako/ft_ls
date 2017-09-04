
#include "/home/cthulhu/42/ft_ls/lib42/libft/libft.h"
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{

		if (argc != 2)
		{
				ft_putendl("Need a path to any file!");
				exit(1);
		}

		char		*path = ft_strdup(*(argv + 1));
		struct stat	fs;
		int			ret = 0;

		//create FIFO file
		//ret = mkfifo("./fifo", O_WRONLY);
		//printf("Making fifo = %d\n", ret);

		ft_putstr("file: ");
		ft_putendl(path);
		ft_putendl("");
		ret = stat(path, &fs);
		if (ret != 0)
		{
			ft_putendl("File error!");
			exit(1);
		}

		//device
		printf("st_dev		= %x\n", fs.st_dev);
		printf("st_rdev		= %x\n", fs.st_rdev);
		printf("\tmajor=%d\n", major(fs.st_dev));
		printf("\tminor=%d\n", minor(fs.st_dev));
		printf("\trmajor=%d\n", major(fs.st_rdev));
		printf("\trminor=%d\n", minor(fs.st_rdev));

		//inode
		printf("st_inode	= %x\n", fs.st_ino);

		//mode
		char *xa = NULL;
		xa = ft_strnew(666);
		ft_putstr("st_mode\t\t= ");
		S_ISDIR(fs.st_mode)  ? ft_putchar('d'): 0;
		S_ISREG(fs.st_mode)  ? ft_putchar('-'): 0;
		S_ISLNK(fs.st_mode)  ? ft_putchar('l'): 0;
		S_ISCHR(fs.st_mode)  ? ft_putchar('c'): 0;
		S_ISBLK(fs.st_mode)  ? ft_putchar('b'): 0;
		S_ISFIFO(fs.st_mode) ? ft_putchar('p'): 0;
		fs.st_mode & S_IRUSR ? ft_putchar('r'): ft_putchar('-');
		fs.st_mode & S_IWUSR ? ft_putchar('w'): ft_putchar('-');
		fs.st_mode & S_IXUSR ? ft_putchar('x'): ft_putchar('-');
		fs.st_mode & S_IRGRP ? ft_putchar('r'): ft_putchar('-');
		fs.st_mode & S_IWGRP ? ft_putchar('w'): ft_putchar('-');
		fs.st_mode & S_IXGRP ? ft_putchar('x'): ft_putchar('-');
		fs.st_mode & S_IROTH? ft_putchar('r'): ft_putchar('-');
		fs.st_mode & S_IWOTH? ft_putchar('w'): ft_putchar('-');
		fs.st_mode & S_IXOTH? ft_putchar('x'): ft_putchar('-');
		listxattr(path, xa, 666) >= 0 ? ft_putchar('+') : 0;
		ft_putendl("");

		//nlink
		printf("st_nlink	= %d link(s)\n",fs.st_nlink);

		//uid
		printf("st_uid		= %d\n", fs.st_uid);
		struct passwd *passwd = NULL;
		passwd = getpwuid(fs.st_uid);
		printf("\tname = %s\n", (*passwd).pw_name);
		printf("\tpassword = %s\n", (*passwd).pw_passwd);
		printf("\tuid = %d\n", (*passwd).pw_uid);
		printf("\tgid = %d\n", (*passwd).pw_gid);
		printf("\tinfos = %s\n", (*passwd).pw_gecos);
		printf("\thome = %s\n", (*passwd).pw_dir);
		printf("\tshell = %s\n", (*passwd).pw_shell);

		//gid
		printf("st_gid		= %d\n", fs.st_gid);
		struct group *group = NULL;
		group = getgrgid(fs.st_gid);
		printf("\tname = %s\n", (*group).gr_name);
		printf("\tpasswd = %s\n", (*group).gr_passwd);
		printf("\tgid = %d\n", (*group).gr_gid);

		int count = 0;
		while (*((*group).gr_mem + count) != NULL)
		{
			printf("\tmembers[%d] = %s\n", count, *((*group).gr_mem + 0));
			count++;
		}

		//rdev
		printf("st_rdev		= %d\n", fs.st_rdev);

		//size
		printf("st_size		= %d bytes\n", fs.st_size);

		//block size
		printf("st_blksize	= %d bytes\n", fs.st_blksize);

		//blocks
		printf("st_blocks	= %d blocks\n", fs.st_blocks);

		//access time
		printf("access time	= %s", ctime((time_t*)&fs.st_atim));

		//access time
		printf("modif  time	= %s", ctime((time_t*)&fs.st_mtim));

		//birth time
		printf("status time	= %s", ctime((time_t*)&fs.st_ctim));

		//current timeA
		time_t sec;
		sec = time(NULL);
		printf("current time	= %s\n", ctime(&sec));

#define size 24
		//xattr
		char *xattr = NULL;
		xattr = (char *)malloc(sizeof(*xattr) * size);
		ret = listxattr(path, xattr, size);
		printf("xattr list = %d bytes\n", ret);
		ft_print_memory(xattr, 256);
		printf("%s\n", xattr);

		return(0);
}
