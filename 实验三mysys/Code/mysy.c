#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

void mysys(char *  commond)
{
	char  aa[105];
	strcpy(aa,commond);
	pid_t pid;
	pid=fork();

	if(pid==0)
	{
		char *argv[30];
		int i=0;
		char *  ss;
		ss=strtok(aa," ");
		while(ss)
		{
			argv[i]=ss;
			printf("%s ",argv[i]);
			i++;
			ss=strtok(NULL," ");
		}
		argv[i]=NULL;
		int error=execvp(argv[0],argv);
		if(error<0)
			printf("execvp error");
		printf("\n");
	}
	wait(NULL);

}

int main()
{
	printf("--------------------------------------------------\n");
    mysys("echo HELLO WORLD");
    printf("-------------------------------------------------\n-");
    mysys("ls /");
    printf("--------------------------------------------------\n");
	return 0;
}
