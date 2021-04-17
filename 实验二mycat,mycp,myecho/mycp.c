#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define MAX_SIZE 1024
int main(int argc,char *argv[])
{
	char buffer[MAX_SIZE];
	int fd1=open(argv[1],O_RDONLY,0777);
	if(!fd1)
		printf("first cant not open");
	int fd2=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0777);
	if(!fd2)
		printf("second can not open");
	int size1=0;
	while(size1=read(fd1,buffer,MAX_SIZE))
	{
		if(size1<MAX_SIZE)
			buffer[size1-1]='\0';
		
		write(fd2,buffer,size1);
	}
	close(fd1);
	close(fd2);
	return 0;
} 