// write a shared memory program where there are 2 programs
// reader – reads the values from shared memory, calculates nCr value and prints it

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
	int *n = (int*)shmat(shmid, (void*)0, 0);
	printf("Data read from shared memory:\n%d\n", *n);
	int m = *n, i = 0, d, r = 0;

	while(m > 0)
	{
		d = m % 10;
		r = r * 10 + d;
		m = m / 10;
	}

	if(r == *n)
	{
		printf("Palindrome");
	}

	else
	{
		printf("Not palindrome");
	}

	printf(" because reverse is:\n%d\n", r);
	shmdt(n);
	shmctl(shmid, IPC_RMID, NULL);
}
