// implement opendir & readdir

#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

void main()
{
	DIR *dirp;
	struct dirent *dp;

	// doesn't apply here
	if((dirp = opendir("./")) == NULL)
	{
		printf("Directory doesn't exist\n");
		exit(1);
	}

	for(dp = readdir(dirp); dp != NULL; dp = readdir(dirp))
	{
		if(dp->d_type == DT_REG)
		{
			printf("%s\n", dp->d_name);
		}
	}

	closedir(dirp);
}
