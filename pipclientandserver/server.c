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
	char ch[1024];
	while(1){
	int n=read(fd,ch,1024);

	write(STDERR_FILENO,ch,n);
	
	}
	return 0;

}
