// simulate the following cpu scheduling algorithms
// fcfs

#include <stdio.h>

void main()
{
	int at[10], bt[10], ct[10], tt[10], wt[10], n, i;
	float twt = 0, ttt = 0;
	printf("Enter number of processes:\n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("Enter arrival time of process %d:\n", i + 1);
		scanf("%d", &at[i]);
		printf("Enter burst time of process %d:\n", i + 1);
		scanf("%d", &bt[i]);
	}

	wt[0] = 0;
	ct[0] = bt[0];
	tt[0] = bt[0];

	for(i = 1; i < n; i++)
	{
		ct[i] = ct[i-1] + bt[i];
		wt[i] = ct[i-1] - at[i];
		tt[i] = tt[i-1] + at[i-1] + bt[i] - at[i];
	}

	printf("\nProcess\tAT\tBT\tTT\tWT\n");

	for(i = 0; i < n; i++)
	{
		twt += wt[i];
		ttt += tt[i];
		printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], tt[i], wt[i]);
	}

	printf("\nAverage turnaround time = %f\n", ttt / n);
	printf("Average waiting time = %f\n", twt / n);
}
