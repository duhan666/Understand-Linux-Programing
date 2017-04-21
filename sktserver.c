
        

        #include <sys/types.h>          /* See NOTES */
        #include <sys/socket.h>
	    #include <stdio.h>
		#include <stdlib.h>
		#include <netinet/in.h>
		#include <netdb.h>
		#include <unistd.h>
		#include <string.h>
		#include <time.h>
		#include <arpa/inet.h>



int main(){

	char hostname[256];



	struct sockaddr_in myipv4sock;

	memset(&myipv4sock,0,sizeof(struct sockaddr_in));

	myipv4sock.sin_family = AF_INET;
	myipv4sock.sin_port   = htons(13157);
	myipv4sock.sin_addr.s_addr = inet_addr("192.168.1.120");


	int skt_id = socket(AF_INET,SOCK_STREAM,0);
	if(skt_id == -1)printf("socket error!\n");
	printf("skt_id is %d\n",skt_id);

	int bid_id = bind(skt_id,(struct sockaddr*)&myipv4sock,sizeof(struct sockaddr_in));
	if(bid_id == -1)printf("bind error!\n");
	printf("bid_id is %d\n",bid_id);

	int lsn_id = listen(skt_id,1);
	if(lsn_id == -1)printf("listen error!\n");

	while(1){
		int accp_id = accept(skt_id,NULL,NULL);
		if(accp_id == -1)printf("accept error!\n");
		printf("Wow,get a call!\n");

		FILE* sock_fp = fdopen(accp_id,"w");

		time_t thetime = time(NULL);
		char* str = ctime(&thetime);
		
		printf("begin to print time&date\n");

		fprintf(sock_fp,"the time here is...");
		fprintf(sock_fp,"%s",str);

		fclose(sock_fp);
	}

}
