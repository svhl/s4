// memory allocation methods for fixed partition using linked list
// first fit, worst fit & best fit

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *proc, *head, *tail, *ptr;
int item;

void main()
{
	int i, j, p, m, ch, temp;
	printf("Enter no. of memory partitions:\n");
	scanf("%d", &m);
	printf("Enter no. of processes:\n");
	scanf("%d", &p);
	int mem[m];
	printf("Enter sizes of memory partitions:\n");

	for(i = 0; i < m; i++)
	{
		scanf("%d", &mem[i]);
	}

	printf("Enter sizes of processes:\n");

	for(i = 0; i < p; i++)
	{
		proc = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &proc->data);
		proc->next = NULL;

		if(head == NULL)
		{
			head = proc;
			tail = proc;
		}

		else
		{
			tail->next = proc;
			tail = proc;
		}
	}

	printf("\nMenu\n");
	printf("1. First fit\n");
	printf("2. Best fit\n");
	printf("3. Worst fit\n");
	printf("Any other value to exit\n");
	printf("Enter choice:\n");
	scanf("%d", &ch);

	if(ch == 1)
	{
		printf("\nFirst fit:\n");	
	}

	else if(ch == 2)
	{
		printf("\nBest fit:\n");

		for(i = 0; i < m - 1; i++)
		{
			for(j = 0; j < m - i - 1; j++)
			{
				if(mem[j] > mem[j+1])
				{
					temp = mem[j];
					mem[j] = mem[j+1];
					mem[j+1] = temp;
				}
			}
		}
	}

	else if(ch == 3)
	{
		printf("\nWorst fit:\n");

		for(i = 0; i < m - 1; i++)
		{
			for(j = 0; j < m - i - 1; j++)
			{
				if(mem[j] < mem[j+1])
				{
					temp = mem[j];
					mem[j] = mem[j+1];
					mem[j+1] = temp;
				}
			}
		}
	}

	else
	{
		printf("\nWrong choice\n");
		return;
	}

	ptr = head;
	i = 1;

	while(ptr != NULL)
	{
		for(j = 0; j < m; j++)
		{
			if(ptr->data <= mem[j])
			{
				printf("P%d allocated to block %d\n", i, mem[j]);
				mem[j] = 0;
				break;
			}
		}

		if(j == m)
		{
			printf("P%d can't be allocated\n", i);
		}

		ptr = ptr->next;
		i++;
	}
}
