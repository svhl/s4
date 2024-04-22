// write a shared memory program where there are 2 programs
// reader – reads and counts no. of vowels, symbols & numbers in it

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *str = (char*)shmat(shmid, (void*)0, 0);
	printf("Data read from shared memory:\n%s\n", str);
	int v = 0, n = 0, s = 0, i;

	for(i = 0; i < strlen(str); i++)
	{
		char c = tolower(str[i]);

		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			v++;
		}

		else if(c >= '0' && c <= '9')
		{
			n++;
		}

		else if(c != ' ')
		{
			s++;
		}
	}

	printf("No. of vowels = %d\nNo. of symbols = %d\nNo. of numbers = %d\n", v, s, n);
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);
}
