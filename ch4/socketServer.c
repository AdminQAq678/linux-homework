/**
 *使用TCP监听3030端口，支持多个客户端俩捏连接，
 使用消息队列去实现子线程与父线程通信问题，同时可附加命令
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>


#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SERVER_PORT 3030
char * fdarrays;    	//进程共享的变量
int num=0;
int main (int argc, char *argv[]){
	printf("ok");
	int sockfd, connfd, nbytes,addrlen, maxfd, keychars, sockchars, retval,pid;
	fd_set rfds, wfds;//可读的描述符

	
	char buf [1024], buf1[1024], buf2[1024];
	struct sockaddr_in srvaddr, cliaddr;
	struct timeval tv; 
	
	//共享内存变量定义
	int shmid,status;
	char *shamaddr;

	shmid=shmget(IPC_PRIVATE, 4096 , IPC_CREAT | 0600);
	if(shmid<0){
		perror("shget error!");
		exit(-1);
	}
	fdarrays =(char  *) shmat(shmid,NULL,0);//连接共享内存
	if(fdarrays==(void *)-1){
		perror(" shmat error in child process\n");
		exit(-1);
	}


	if( (sockfd=socket(AF_INET, SOCK_STREAM,0))== -1){
		perror(" create socket error ");
		return -1;
	
	}

	bzero(&srvaddr, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port=htons(SERVER_PORT);
	srvaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	addrlen=sizeof(struct sockaddr);

	if(bind(sockfd,(struct sockaddr *) & srvaddr, addrlen)==-1){
		perror("端口绑定错误");
		return -2;
	}
	
	if(listen(sockfd,5)==-1){
		perror("舰艇错误");
		return -1;

	}


	

	
	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	fdarrays[0]=1;;
	while(1){

		printf("监听中");
		connfd=accept(sockfd,(struct sockaddr *)& cliaddr, &addrlen);

		fdarrays[fdarrays[0]++]=connfd;
		for( int i=0;i<=fdarrays[0];i++){

			printf("%d+++++",fdarrays[i]);  
		}
		
		printf("\nnums:%d\nconnfd:%d\n",num,connfd);
		pid=fork();
		if(pid==0){
			
			printf(" 服务器: 获得来自%s, 端口为: %d\n的连接",inet_ntoa(cliaddr.sin_addr),htons(cliaddr.sin_port));
			maxfd=(connfd >sockfd) ? connfd : sockfd;//获得最大的文件描述符

		for( int i=0;i<=fdarrays[0];i++){

			printf("%d+++++",fdarrays[i]);  
		}
			

			while(1){

				
				FD_SET(connfd, &rfds);
				FD_SET(STDIN_FILENO,&rfds);

				tv.tv_sec =0;
				tv.tv_usec=100000; //等待100ms
		
				retval=select (maxfd+1, &rfds, &wfds, NULL,&tv);// 返回fd 的总数，错误时候返回SOCKET_ERROR

				if(FD_ISSET(STDIN_FILENO,&rfds)){
					keychars = read(STDIN_FILENO, buf1,1024);
					write(connfd,buf1,keychars);
				}

				if(FD_ISSET(connfd,&rfds)){
					sockchars = read(connfd, buf2,1024);
					write(STDOUT_FILENO,buf2,sockchars);
				}

			}
		}else{
			close(connfd);
		}




	
	}
	close(sockfd);


	return 0;

}

