// implement exec

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{ 
	char *args[]={"./prog3b2", NULL};
	execvp(args[0], args);
	printf("This line won't be printed");
}
