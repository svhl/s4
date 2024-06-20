// simulate the following disk scheduling algorithms
// fcfs, scan & c-scan

#include <stdio.h>

void main()
{
	int i, j, n, head, c, temp, ch, res, tot = 0;
	char d;
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

	else if(ch == 2)
	{	
		printf("Enter size of cylinder:\n");
		scanf("%d", &c);
		printf("Enter direction (r/l):\n");
		scanf("%c", &d);
		scanf("%c", &d);
		temp = head;

		if(d == 'r')
		{	
			for(i = head; i < c; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = req[j] - temp;
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}

			res = c - 1 - temp;
			tot += res;
			printf("\n%d -> %d = %d", temp, c - 1, res);
			temp = c - 1;

			for(i = head; i > 0; i--)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = temp - req[j];
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}
		}

		else if(d == 'l')
		{
			for(i = head; i > 0; i--)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = temp - req[j];
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}

			tot += temp;
			printf("\n%d -> 0 = %d", temp, temp);
			temp = 0;

			for(i = head; i < c; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = req[j] - temp;
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}
		}

		else
		{
			printf("Invalid direction\n");
		}
	}

	else if(ch == 3)
	{
		printf("Enter size of cylinder:\n");
		scanf("%d", &c);
		printf("Enter direction (r/l):\n");
		scanf("%c", &d);
		scanf("%c", &d);
		temp = head;

		if(d == 'r')
		{
			for(i = head; i < c; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = req[j] - temp;
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}

			res = c - 1 - temp;
			tot += res;
			printf("\n%d -> %d = %d", temp, c - 1, res);
			res = c - 1;
			tot += res;
			printf("\n%d -> 0 = %d", c - 1, res);
			temp = 0;

			for(i = 0; i < head; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = req[j] - temp;
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}
		}

		else if(d == 'l')
		{
			for(i = head; i > 0; i--)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = temp - req[j];
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}

			tot += temp;
			printf("\n%d -> 0 = %d", temp, res);
			res = c - 1;
			tot += res;
			printf("\n0 -> %d = %d", c - 1, res);
			temp = c - 1;

			for(i = c - 1; i > head; i--)
			{
				for(j = 0; j < n; j++)
				{
					if(req[j] == i)
					{
						res = temp - req[j];
						tot += res;
						printf("\n%d -> %d = %d", temp, req[j], res);
						temp = req[j];
					}
				}
			}
		}

		else
		{
			printf("Invalid direction\n");
		}
	}

	else
	{
		printf("Wrong choice\n");
		return;
	}

	printf("\n\nTotal seek operations = %d\n", tot);
}
