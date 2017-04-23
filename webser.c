
#include <stdio.h>
 #include <netinet/in.h>
       #include <sys/types.h>  
       #include <sys/socket.h>


int make_socket(){
	
	int skt_fd = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in addr;

	//memset(&myipv4sock,0,sizeof(struct sockaddr_in));

	addr.sin_family = AF_INET;
	addr.sin_port   = htons(13157);
	addr.sin_addr.s_addr = inet_addr("192.168.1.103");


	int bind_id = bind(skt_fd,(struct sockaddr *)&addr,sizeof(addr));

	if(bind_id == -1)
		printf("bind error\n");

}

void main(){

	make_socket();
}


