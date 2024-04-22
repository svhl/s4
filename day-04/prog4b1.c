// write a shared memory program where there are 2 programs
// writer – wrties a string into shared memory

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *str = (char*)shmat(shmid, (void*)0, 0);
	printf("Enter string:\n");
	gets(str);
	printf("Data written in shared memory:\n%s\n", str);
	shmdt(str);
}
