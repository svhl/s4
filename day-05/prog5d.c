// simulate the following cpu scheduling algorithms
// priority (non-preemptive)

#include <stdio.h>

void main()
{
	int at[10], bt[10], tt[10], wt[10], p[10], c = 0, n, i;
	float twt = 0, ttt = 0;
	printf("Enter number of processes:\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter arrival time of process %d:\n", i + 1);
		scanf("%d", &at[i]);
		printf("Enter burst time of process %d:\n", i + 1);
		scanf("%d", &bt[i]);
		printf("Enter priority of process %d:\n", i + 1);
		scanf("%d", &p[i]);
	}

	wt[0] = 0;
	tt[0] = bt[0];;
	c = tt[0];

	for(i = 1; i < n; i++)
	{
		wt[i] = c - at[i];
		tt[i] = c + bt[i] - at[i];
		c += bt[i];
	}

	printf("\nProcess\tAT\tBT\tTT\tWT\n");

	for(i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], p[i], tt[i], wt[i]);
		ttt += tt[i];
		twt += wt[i];
	}

	printf("\nAverage turnaround time = %f\n", ttt / n);
	printf("Average waiting time = %f\n", twt / n);
}
