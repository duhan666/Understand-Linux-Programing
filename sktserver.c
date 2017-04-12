
       #include <sys/types.h>          /* See NOTES */
       #include <sys/socket.h>



int main(){

	int skt_id = socket(AF_INET,SOCK_STREAM);
	if(skt_id == -1)printf("socket error!\n");

	int bid = bind(skt_id,)

}