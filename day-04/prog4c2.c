// write a shared memory program where there are 2 programs
// reader – reads it from shared memory & checks whether palindrome

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
	int *n = (int*)shmat(shmid, (void*)0, 0);
	printf("Data read from shared memory:\n%d\n", *n);
	int m = *n, r = 0;

	while(m != 0)
	{
		r = r * 10 + (m % 10);
		m /= 10;
	}

	if(r == *n)
	{
		printf("Palindrome\n");
	}

	else
	{
		printf("Not palindrome\n");
	}

	shmdt(n);
	shmctl(shmid, IPC_RMID, NULL);
}
