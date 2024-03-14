// simulate cpu scheduling algorithm
// sjf (non pre-emptive)

#include <stdio.h>

void main()
{

	int pid[10], bt[10], wt[10], i, j, n, pos, temp;
	float twt = 0.0, tat = 0.0, awt, att;
	wt[0] = 0;
	printf("Enter no. of process:\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter pid of process %d:\n", i + 1);
		scanf("%d", &pid[i]);
		printf("Enter burst time of process %d:\n", i + 1);
		scanf("%d", &bt[i]);
		wt[i+1] = bt[i] + wt[i];
	}

	for(i = 0; i < n; i++)
	{
		pos = i;

		for(j = i + 1; j < n; j++)
		{
			if(bt[j] < bt[pos])
			{
				pos = j;
			}
		}

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;
		temp = pid[i];
		pid[i] = pid[pos];
		pid[pos] = temp;
	}

	for(i = 1; i < n; i++)
	{

		wt[i] = 0;

		for(j = 0; j < i;j++)
		{
	    		wt[i] += bt[j];
	    	}

		twt += wt[i];
	}

	printf("\nProcess ID\tBurst time\tWaiting time\tTurnaround time\n");

	for(i = 0; i < n; i++)
	{
		tat = tat + bt[i] + wt[i];
		printf("%d\t\t", pid[i]);
		printf("%d\t\t", bt[i]);
		printf("%d\t\t", wt[i]);
		printf("%d\t\t\n", bt[i]+ wt[i]);
	}

	awt = twt / n;
	att = tat / n;
	printf("\nAverage waiting time:\n%f\n", awt);
	printf("Average turnaround time:\n%f\n", att);
}
