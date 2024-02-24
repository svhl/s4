// implement close

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	// file test.txt should exist
	int fd1 = open("test.txt", O_RDONLY);
	
	if(fd1 < 0)
	{
		printf("Error or file doesn't exist\n");
		exit(1);
	}

	printf("Opened with file descriptor %d\n", fd1);

	if(close(fd1) < 0)
	{
		printf("Error\n");
		exit(1);
	}

	printf("Closed file descriptor\n");
}
