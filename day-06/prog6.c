// implement producer-consumer using semaphores

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int front = -1, rear = 0, mutex = 1, q[10], i, n;

void producer()
{
	mutex--;
	front++;
	printf("Produced item at %d\n", front);
	printf("Item produced is ");
	scanf("%d", &n);
	q[rear] = n;
	rear++;
	mutex++;
}

void consumer()
{
	mutex--;
	rear--;
	n = q[rear];
	printf("Consumed item at %d\n", front);
	printf("Item consumed is %d\n", n);
	front--;
	mutex++;
}

void main()
{
	srand(time(NULL));

	for(i = 0; i < 10; i++)
	{
		n = (rand() % 10) + 1;
		printf("#%d Random number is %d\n", i, n);

		if(n % 2 != 0)
		{
			if(mutex == 1)
			{
				producer();
			}

			else
			{
				printf("Can't produce item\nQueue full\n");
			}
		}

		else
		{
			if(mutex == 1 && front != -1)
			{
				consumer();
			}

			else
			{
				printf("Can't consume item\nQueue empty\n");
			}
		}
	}
}
