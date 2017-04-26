

#include "webserlib.c"

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


	}
	return 1;

}