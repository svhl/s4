// implement getpid

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
	pid_t pid;
	pid = fork();

	if(pid == 0)
	{
		printf("Child pid is %d\n", getpid());
	}

	else if(pid > 0)
	{
		printf("Parent pid is %d\n", getppid());
	}
}
