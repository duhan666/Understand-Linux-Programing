

/*
int create_socket(int portnum,int backlog)
int create_connect(int portnum)
*/
#include "webserlib.c"
#include <string.h>
#include <wait.h>
#include <unistd.h>

void process_talk(int fd){
	int pid = fork();
	char* nowtime = timeofnow();
	int len = strlen(nowtime);
	switch(pid){
		case -1: 
			printf("fork error!\n");break;
		case 0:
			write(fd,nowtime,len);
			printf("hahaha\n");
		default:
			wait(NULL);
	}
}

int main(){

	int sockid = create_socket(13000,2);
	if(sockid == -1){
		printf("create_socket ERROR!\n");
		return -1;
	}

	while(1){
		
		int fd = accept(sockid,NULL,NULL);
		if(fd == -1)
			return -1;
		else
			printf("client accept!\n");

		process_talk(fd);

	}
	return 1;

}