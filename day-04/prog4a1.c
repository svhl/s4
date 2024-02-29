// write a shared memory program where there are 2 programs
// writer – finds the n!, r! & (n-r)! value of a given n & r and writes to shared memory

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int fact(int n)
{
	int i = 1, f = 1;
	
	while(i <= n)
	{
		f *= i;
		i++;
	}
	
	return f;
}

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 3 * sizeof(int), 0666 | IPC_CREAT);
	int *n1 = (int*)shmat(shmid, (void*)0, 0);
	int *n2 = n1 + 1;
	int *n3 = n2 + 1;
	int n, r;
	printf("Enter value of n:\n");
	scanf("%d", &n);
	*n1 = fact(n);
 	printf("Enter value of r:\n");       
	scanf("%d", &r);
	*n2 = fact(r);
	n = n - r;
	*n3 = fact(n);
	printf("Data written in shared memory:\nn! = %d\nr! = %d\n(n - r)! = %d\n", *n1, *n2, *n3);
	shmdt(n1);
	shmdt(n2);
	shmdt(n3);
}
