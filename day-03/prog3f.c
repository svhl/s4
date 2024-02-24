// implement stat

#include <stdio.h>
#include <sys/stat.h>

void main()
{
	struct stat sfile;
	// file test.txt should exist
	stat("test.txt", &sfile);
	printf("Inode number is %ld\n", sfile.st_ino);
	printf("Size is %ld\n", sfile.st_size);
}
