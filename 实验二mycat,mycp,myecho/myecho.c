#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	if(argc==1)
	{
		printf("error");
		exit(0);
	}
	for(int i=1;i<argc;i++)
		printf("%s ",argv[i]);
    printf("\n");
	return 0;
} 