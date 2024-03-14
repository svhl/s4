// simulate cpu scheduling algorithm
// fcfs

#include <stdio.h>

void main()
{
	int pid[10], bt[10], wt[10], n, i;
	float twt = 0.0, tat = 0.0, att, awt;
	wt[0] = 0;
	printf("Enter no. of processes:\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter pid of process %d:\n", i + 1);
		scanf("%d", &pid[i]);
		printf("Enter burst time of process %d:\n", i + 1);
		scanf("%d", &bt[i]);
		wt[i+1] = bt[i] + wt[i];
	}

	printf("\nProcess ID\tBurst time\tWaiting time\tTurnaround time\n");

	for(i = 0; i < n; i++)
	{
		printf("%d\t\t", pid[i]);
		printf("%d\t\t", bt[i]);
		printf("%d\t\t", wt[i]);
		printf("%d\n", bt[i] + wt[i]);
		twt = twt + wt[i];
		tat = tat + wt[i] + bt[i];
	}

	awt = twt / n;
	att = tat / n;
	printf("\nAverage waiting time:\n%f\n", awt);
	printf("Average turnaround time:\n%f\n", att);
}
