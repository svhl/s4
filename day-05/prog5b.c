// simulate the following cpu scheduling algorithms
// sjf (non-preemptive)

#include <stdio.h>

void main()
{
	int at[10], bt[10], tt[10], wt[10], c[10] = {0}, t = 0, s, n, i;
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

	printf("\nProcess\tAT\tBT\tTT\tWT\n");

	while(1)
	{
		s = -1;

		for(i = 0; i < n; i++)
		{
			if (c[i] == 0 && at[i] <= t)
			{
				if(s == -1 || bt[i] < bt[s])
				{
					s = i;
				}
			}
		}

		if(s == -1)
		{
			break;
		}

		c[s] = 1;
		printf("%d\t%d\t%d\t%d\t%d\n", s + 1, at[s], bt[s], t + bt[s] - at[s], t - at[s]);
		tt[s] = t + bt[s] - at[s];
		wt[s] = t - at[s];
		ttt += tt[s];
		twt += wt[s];
		t += bt[s];
	}

	printf("Average turnaround time = %f\n", ttt / n);
	printf("\nAverage waiting time = %f\n", twt / n);
}
