// write a shared memory program where there are 2 programs
// writer – wrties a no. to shared memory

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
	int *n = (int*)shmat(shmid, (void*)0, 0);
	printf("Enter a number:\n");
	scanf("%d", &n);
	printf("Data written in shared memory:\n%d\n", n);
	shmdt(n);
}
