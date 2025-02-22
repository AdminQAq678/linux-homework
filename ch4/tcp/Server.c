#include<stdio.h>  
#include<stdlib.h>  
#include<netinet/in.h>  
#include<sys/socket.h>  
#include<arpa/inet.h>  
#include<string.h>  
#include<unistd.h>  

#define BACKLOG 5     //完成三次握手但没有accept的队列的长度  
#define CONCURRENT_MAX 8   //应用层同时可以处理的连接  
#define SERVER_PORT 3030  
#define BUFFER_SIZE 1024  
#define QUIT_CMD ".quit"  
#define MSG_TO

char **devarray;//传感器设备名称数组
struct devnode{	//设备名称和connfd映射结构体，用于根据设备名称发送消息
	char *name;
	int connfd;	
}devnode;



//添加传感器客户端的唯一标识
int client_fds[CONCURRENT_MAX];

struct devnode devNodes[CONCURRENT_MAX];
//服务器发送信息到客户端
void sendTo(int fd, char *msg){


}

void devNodesInit (){
//初始化结构体
for(int i=0;i<CONCURRENT_MAX;i++){
	devNodes[i].name="";
	devNodes[i].connfd=0;

}

}
//截取字符串函数
char *  subString(char *seq, int begin, int end){
	char * tem=(char *) malloc(sizeof(char)*(end-begin+1));
	int j=0;
	for(int i=0;i<strlen(seq);i++){
		if(i>=begin&&i<end){
			tem[j++]=seq[i];
		}	
	}
	return tem;

}
int main(int argc, const char * argv[])  
{ 
	devNodesInit();//初始化devNodes结构体
    
	char input_msg[BUFFER_SIZE];  
    char recv_msg[BUFFER_SIZE];  
    //本地地址  
    struct sockaddr_in server_addr;  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_port = htons(SERVER_PORT);  
    server_addr.sin_addr.s_addr = INADDR_ANY;  
    bzero(&(server_addr.sin_zero), 8);  
    //创建socket  
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);  
    if(server_sock_fd == -1)  
    {  
        perror("socket error");  
        return 1;  
    }  
    //绑定socket  
    int bind_result = bind(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));  
    if(bind_result == -1)  
    {  
        perror("bind error");  
        return 1;  
    }  
    //listen  
    if(listen(server_sock_fd, BACKLOG) == -1)  
    {  
        perror("listen error");  
        return 1;  
    }  
    //fd_set  
    fd_set server_fd_set;  
    int max_fd = -1;  
    struct timeval tv;  //超时时间设置  
    while(1)  
    {  
        tv.tv_sec = 20;  
        tv.tv_usec = 0;  
        FD_ZERO(&server_fd_set);  
        FD_SET(STDIN_FILENO, &server_fd_set);  
        if(max_fd <STDIN_FILENO)  
        {  
            max_fd = STDIN_FILENO;  
        }  
        //printf("STDIN_FILENO=%d\n", STDIN_FILENO);  
    //服务器端socket  
        FD_SET(server_sock_fd, &server_fd_set);  
       // printf("server_sock_fd=%d\n", server_sock_fd);  
        if(max_fd < server_sock_fd)  
        {  
            max_fd = server_sock_fd;  
        }  
    //客户端连接  
        for(int i =0; i < CONCURRENT_MAX; i++)  
        {  
           printf("client_fds[%d]=%d\n", i, client_fds[i]);  
            if(client_fds[i] != 0)  
            {  
                FD_SET(client_fds[i], &server_fd_set);  
                if(max_fd < client_fds[i])  
                {  
                    max_fd = client_fds[i];  
                }  
            }  
        }  
        int ret = select(max_fd + 1, &server_fd_set, NULL, NULL, &tv);  
        if(ret < 0)  
        {  
            perror("select 出错\n");  
            continue;  
        }  
        else if(ret == 0)  
        {  
            printf("select 超时\n");  
            continue;  
        }  
        else  
        {  
            //ret 为未状态发生变化的文件描述符的个数  
            if(FD_ISSET(STDIN_FILENO, &server_fd_set))  
            {  
		
                printf("发送消息：\n");  
                bzero(input_msg, BUFFER_SIZE);  
                fgets(input_msg, BUFFER_SIZE, stdin);  
                //输入“.quit"则退出服务器  
                if(strcmp(input_msg, QUIT_CMD) == 0)  
                {  
                    exit(0);  
                }else{
			printf("判断客户端要发送的数据");
				
                	printf("%s\n",subString(input_msg,0,7));
                	if(strcmp(subString(input_msg,0,7),"MSG_TO:")==0){
				
				printf("发送信息到......%s客户端\n",subString(input_msg,7,8));
			}	
		}	
		
                for(int i = 0; i < CONCURRENT_MAX; i++)  
                {  

		    //广播信息
                    if(client_fds[i] != 0)  
                    {  
			printf("devnodes__fds%d------Name:%s----",devNodes[i].connfd,devNodes[i].name);
                        printf("client_fds[%d]=%d\n", i, client_fds[i]);  
                        send(client_fds[i], input_msg, BUFFER_SIZE, 0);  
                    }  
                }  
            }  
            if(FD_ISSET(server_sock_fd, &server_fd_set))  
            {  
                //有新的连接请求  
                struct sockaddr_in client_address;  
                socklen_t address_len;  
                int client_sock_fd = accept(server_sock_fd, (struct sockaddr *)&client_address, &address_len);  
                printf("new connection client_sock_fd = %d\n", client_sock_fd);  
                if(client_sock_fd > 0)  
                {  
                    int index = -1;  
                    for(int i = 0; i < CONCURRENT_MAX; i++)  
                    {  
                        if(client_fds[i] == 0)  
                        {  
                            index = i;  
                            client_fds[i] = client_sock_fd;
			    devNodes[i].connfd=client_sock_fd;//保存sockfd	  

			      
                            break;  
                        }  
                    }  
                    if(index >= 0)  
                    {  
                        printf("新客户端(%d)加入成功 %s:%d\n", index, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));  
                    }  
                    else  
                    {  
                        bzero(input_msg, BUFFER_SIZE);  
                        strcpy(input_msg, "服务器加入的客户端数达到最大值,无法加入!\n");  
                        send(client_sock_fd, input_msg, BUFFER_SIZE, 0);  
                        printf("客户端连接数达到最大值，新客户端加入失败 %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));  
                    }  
                }  
            }  
            for(int i =0; i < CONCURRENT_MAX; i++)  
            {  
                if(client_fds[i] !=0)  
                {  
                    if(FD_ISSET(client_fds[i], &server_fd_set))  
                    {  
                        //处理某个客户端过来的消息  
                        bzero(recv_msg, BUFFER_SIZE);  
                        long byte_num = recv(client_fds[i], recv_msg, BUFFER_SIZE, 0);  
                        if (byte_num > 0)  
                        {  
                            if(byte_num > BUFFER_SIZE)  
                            {  
                                byte_num = BUFFER_SIZE;  
                            }  
                            recv_msg[byte_num] = '\0';  
			    //保存设备名称
			    if(strcmp(subString(recv_msg,0,7),"DEVICE+")==0){

				//排除掉回车符号,根据实际的输入去判断，如果客户端在发送设备信息的时候带有回车就需要在这里把回车符号去掉
				devNodes[i].name=subString(recv_msg,7,strlen(recv_msg)-1);
			    } 
			    //判断客户端是否要与其他客户端通信
			    if(strcmp(subString(recv_msg,0,7),"MSG_TO+")==0){
				    for(int j=0;j<CONCURRENT_MAX;j++){
					    //获取消息主体即 ':'后面的信息
					    //
					int end=(int) (strchr(recv_msg,':')-recv_msg);//获得':'的位置，也是设备名的结束位置
					printf("name of device:%s",devNodes[j].name);
					if(strcmp(devNodes[j].name,subString(recv_msg,7,end))==0){
						//匹配到设备
						char * msg=strchr(recv_msg,':');
						printf("客户端(%s)要发送给(%s)的消息是%s\n",devNodes[i].name,devNodes[j].name,msg);	
						
						send(devNodes[j].connfd,msg,BUFFER_SIZE,0);			
						
						break;
					}

				    }
			    } 


                            printf("客户端(%d):%s\n", i, recv_msg);  
                        }  
                        else if(byte_num < 0)  
                        {  
                            printf("从客户端(%d)接受消息出错.\n", i);  
                        }  
                        else  
                        {  
                            FD_CLR(client_fds[i], &server_fd_set);  
                            client_fds[i] = 0;  
			    devNodes[i].connfd=0;
			    devNodes[i].name=NULL;
                            printf("客户端(%d)退出了\n", i);  
                        }  
                    }  
                }  
            }  
        }  
    }  
    return 0;  
}
