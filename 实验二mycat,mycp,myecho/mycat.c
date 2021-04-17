#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("parameters error");
		exit(0);
	}

	int fd=open(argv[1],O_RDONLY,0777);
	if(fd==-1)
		printf("open error");

	char buffer[1055];
	int size;
	while(size=read(fd,buffer,1055))
	{
		if(size<1055)
			buffer[size]='\0';
		printf("%s",buffer);
	}
	close(fd);


	return 0;
} 