


#include<stdio.h>  

#include<signal.h>  

#include<unistd.h>  

#include<stdlib.h> 

 char ** args;

 void exithandle(int  sig)

	 {

		        printf(" : sighup received ");

	 }

 int main(int argc,char ** argv)

	 {

		        args = argv;

			       signal(SIGTERM,SIG_IGN);
				pause();

				             return 0;

	 }
