// simulate the following disk scheduling algorithms
// fcfs, scan & c-scan

#include <stdio.h>

void main()
{
	int i, n, head, ch, res, tot = 0;
	printf("Enter no. of requests:\n");
	scanf("%d", &n);
	int req[n];
	printf("Enter requests:\n");

	for(i = 0; i < n; i++)
	{
		scanf("%d", &req[i]);
	}

	printf("Enter head:\n");
	scanf("%d", &head);

	printf("\nMenu:\n");
	printf("1. FCFS\n");
	printf("2. SCAN\n");
	printf("3. C-SCAN\n");
	printf("Any other value to exit\n");
	printf("Enter choice:\n");
	scanf("%d", &ch);

	if(ch == 1)
	{
		for(i = 0; i < n; i++)
		{
			if(req[i] > head)
			{
				res = req[i] - head;
			}

			else
			{
				res = head - req[i];
			}

			tot += res;

			printf("\n%d -> %d = %d", head, req[i], res);
			
			head = req[i];
		}
	}

	printf("\n\nTotal seek operations = %d\n", tot);
}
