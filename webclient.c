
/*
int create_socket(int portnum,int backlog)
int create_connect(int portnum)
*/


#include "webserlib.c"

#define TIMEBUF 50

void main(){
	int conid = create_connect(13000);
	if(conid == -1){
		printf("create_connect error!\n");
	}
	else
		printf("connect OK\n");

	char nowtime[TIMEBUF]; 

	read(conid,nowtime,TIMEBUF);
	//printf("%s\n",nowtime );
	int t = strlen(nowtime);
	write(1,nowtime,t);
}