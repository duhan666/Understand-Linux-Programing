



        #include <sys/types.h>          /* See NOTES */
        #include <sys/socket.h>
	    #include <stdio.h>
		//#include <stdlib.h>
		#include <netinet/in.h>
		//#include <netdb.h>
		//#include <unistd.h>
		#include <string.h>
		#include <time.h>
		//#include <arpa/inet.h>

int main(){

	int skt_id = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in ipport;

	ipport.sin_family = AF_INET;
	ipport.sin_port   = htons(13157);
	ipport.sin_addr.s_addr = inet_addr("192.168.1.120");

	int con_id = connect(skt_id,(struct sockaddr*)&ipport,sizeof(ipport));
	if(con_id == 0)
		printf("connect Succeed!\n");

	char mesbuf[100];

	int messagelen = read(skt_id,mesbuf,100);

	int tar = write(1,mesbuf,messagelen);



}





