// simulate the following cpu scheduling algorithms
// round robin (preemptive)

#include <stdio.h>

void main()
{
	int at[10], bt[10], t[10], n, m, i, c, tq, tot = 0;
	float ttt = 0, twt = 0;
	printf("Enter number of processes:\n");
	scanf("%d", &n);
	m = n;
	printf("Enter time quantum:\n");
	scanf("%d", &tq);

	for(i = 0; i < n; i++)
	{
		printf("Enter arrival time of process %d:\n", i + 1);
		scanf("%d", &at[i]);
		printf("Enter burst time of process %d:\n", i + 1);
		scanf("%d", &bt[i]);
		t[i] = bt[i];
	}	

	i = 0;
	printf("\nProcess\tAT\tBT\tTT\tWT\n");

	while(n != 0)
	{
		if(t[i] <= tq && t[i] > 0)
		{
			tot += t[i];
			t[i] = 0;
			c = 1;
		}
		
		else if(t[i] > 0)
		{
			t[i] -= tq;
			tot += tq;
		}

		if(t[i] == 0 && c == 1)
		{
			n--;
			printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], tot - at[i], tot - at[i] - bt[i]);
			twt += tot - at[i] - bt[i];
			ttt += tot - at[i];
			c = 0;
		}

		if(at[i + 1] <= tot)
		{
			i++;
		}
		
		else
		{
			i = 0;
		}
	}

	printf("\nAverage turnaround time = %f\n", ttt / m);
	printf("Average waiting Time = %f\n", twt / m);
}
