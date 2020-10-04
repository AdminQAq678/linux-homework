#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
//#include <sys/wait.h>
#include <fcntl.h>

#include <stdio.h>

int main (int argc,char *argv[]){

	int fd;
	mkfifo("fifo",0777);
	fd=open("fifo",O_RDWR);
	if(fd<0){
	perror("file open error.\n");

	}
	if(argc!=2){
		printf("usage: ./%s msg",argv[0]);
		exit(-1);
	}
	char ch[1024];
	while(1){
	int n=read(STDIN_FILENO,ch,1024);
	write(fd,ch,n);
	sleep(2);
	}
	return 0;

}
