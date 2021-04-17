#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

void mysys(char *  cc)
{
	char  aa[105];
	strcpy(aa,cc);
	pid_t pid;
	pid=fork(); 

	if(pid==0)  //子进程调用执行，父进程调用不执行 
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
			printf("error");
		printf("\n");
	}
	wait(NULL); //如果父进程调用等待子进程 

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
