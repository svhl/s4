// simulate the following page replacement algorithms
// fifo & lru

#include <stdio.h>

void main()
{
	int ch, i, j, k, f, p, page[100], pf = 0, t, temp[100], l, lru[100];
	printf("Enter no. of frames:\n");
	scanf("%d", &f);
	printf("Enter no. of pages:\n");
	scanf("%d", &p);
	printf("Enter page requests:\n");

	for(i = 0; i < p; i++)
	{
		scanf("%d", &page[i]);
	}

	printf("\nMenu\n");
	printf("1. FIFO\n");
	printf("2. LRU\n");
	printf("Enter choice:\n");
	scanf("%d", &ch);

	printf("\nPage\t");

	for(i = 0; i < f; i++)
	{
		temp[i] = -1;
		printf("Frame %d\t", i + 1);
	}

	for(i = 0; i < p; i++)
	{
		t = 0;
		l = 0;

		for(j = 0; j < f; j++)
		{
			if(page[i] == temp[j])
			{
				t++;
				pf--;
				lru[j] = i + 1;
			}
		}

		pf++;

		if(pf <= f && t == 0)
		{
			temp[i] = page[i];
			lru[i] = i + 1;
		}

		else if(t == 0)
		{
			if(ch == 1)
			{
				temp[(pf-1)%f] = page[i];
			}

			else if(ch == 2)
			{
				for(k = 0; k < f; k++)
				{
					if(lru[k] < lru[l])
					{
						l = k;
					}
				}

				temp[l] = page[i];
				lru[l] = i + 1;
			}
		}

		printf("\n%d\t", page[i]);

		for(j = 0; j < f; j++)
		{
			if(temp[j] != -1)
			{
				printf("%d\t", temp[j]);
			}

			else
			{
				printf("-\t");
			}
		}
	}

	printf("\n\nTotal page faults = %d\n", pf);
}
