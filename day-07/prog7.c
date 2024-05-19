// implement banker's algorithm

#include <stdio.h>

void main()
{
	int i, j, k, p, r, flag, n = 0;
	printf("Enter no. of processes:\n");
	scanf("%d", &p);
	printf("Enter no. of resources:\n");
	scanf("%d", &r);
	int alloc[p][r], max[p][r], avail[r], need[p][r], ans[p], f[p];
	printf("\nEnter allocation matrix:\n");

	for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
		{
			scanf("%d", &alloc[i][j]);
		}
	}

	printf("\nEnter max matrix:\n");

	for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
		{
			scanf("%d", &max[i][j]);
		}
	}

	printf("\nEnter available resources:\n");

	for(i = 0; i < r; i++)
	{
		scanf("%d", &avail[i]);
	}

	for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}

	for(i = 0; i < p; i++)
	{
		f[i] = 0;
	}

	for(k = 0; k < p; k++)
	{
		for(i = 0; i < p; i++)
		{
			if(f[i] == 0)
			{
				flag = 0;
				
				for(j = 0; j < r; j++)
				{
					if(need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}

				if(flag == 0)
				{
					ans[n] = i;
					n++;

					for(j = 0; j < r; j++)
					{
						avail[j] += alloc[i][j];
					}

					f[i] = 1;
				}
			}
		}
	}

	flag = 1;

	for(i = 0; i < p; i++)
	{
		if(f[i] == 0)
		{
			flag = 0;
			printf("\nSafe sequence doesn't exist\n");
			break;
		}
	}

	if(flag == 1)
	{
		printf("\nSafe sequence:\n");

		for(i = 0; i < p - 1; i++)
		{
			printf("P%d -> ", ans[i]);
		}

		printf("P%d\n", ans[p-1]);
	}
}
