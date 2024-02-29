// write a shared memory program where there are 2 programs
// reader – reads the values from shared memory, calculates nCr value and prints it

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 3 * sizeof(int), 0666 | IPC_CREAT);
	int *n1 = (int*)shmat(shmid, (void*)0, 0);
	int *n2 = n1 + 1;
	int *n3 = n2 + 1;
	printf("Data read from shared memory:\nn! = %d\nr! = %d\n(n - r)! = %d\n", *n1, *n2, *n3);
	int ncr = *n1 * *n2 / *n3;
	printf("nCr = %d\n", ncr);
	shmdt(n1);
	shmdt(n2);
	shmdt(n3);
	shmctl(shmid, IPC_RMID, NULL);
}
