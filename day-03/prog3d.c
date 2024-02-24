// implement wait

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
	pid_t cpid;

	if(fork()== 0)
	{
		exit(0);
	}

	else
	{
		cpid = wait(NULL);
	}

	printf("Parent pid is %d\n", getpid());
	printf("Child pid is %d\n", cpid);
}
