#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc,char * argv[]){
	int fd=open("my",O_APPEND,0777);
	if(fd<0){
		perror("file open error.\n");
		exit(-1);
	}
	char ch[1024];
	int n=read(STDIN_FILENO,ch,1024);
	
	write(STDERR_FILENO,"ok",3);
	write(fd,ch,n);
	
	return 0;
}
