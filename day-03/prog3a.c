// implement fork

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
	fork();
	printf("Hello world!\n");
}
