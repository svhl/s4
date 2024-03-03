// write a shared memory program where there are 2 programs
// reader - counts number of vowels, symbols & numbers in it

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

void main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *str = (char*)shmat(shmid, (void*)0, 0);
	printf("Data read from shared memory:\n%s\n", str);
	int i = 0, v = 0, n = 0, s = 0;

	while(i < strlen(str))
	{
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		{
			v++;
		}

		else if(str[i] >= '0' && str[i] <= '9')
		{
			n++;
		}

		else if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
		{
			s++;
		}

		i++;
	}

	printf("No. of vowels: %d\n", v);
	printf("No. of symbols: %d\n", s);
	printf("No. of numbers: %d\n", n);
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);
}
