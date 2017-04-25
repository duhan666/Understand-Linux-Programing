//temp

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>        
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

#define HOSTNAMELEN 30
//#define PORTNUM 13157

/*
 struct   sockaddr_in    
{    
    short int           sin_family;     //2  
    unsigned short int  sin_port;     //2  
    struct in_addr      sin_addr;      //4  
    unsigned   char     sin_zero[8];     //8  
};   

struct in_addr            
{  
    in_addr_t s_addr;   // in_addr_t一般为32位的unsigned int,其字节顺序为网络字节序，即该无符号数采用大端字节序。其中每8位表示一个IP地址中的一个数值。  
};  

struct hostent{
    char * h_name;
    char ** h_aliases;
    short h_addrtype;
    short h_length;
    char ** h_addr_list;
    #define h_addr h_addr_list[0];
};    

*/

int create_socket(int portnum){
	
	char str[HOSTNAMELEN];
	int h_name = gethostname(str,HOSTNAMELEN);
	if(h_name == -1)printf("get host name error!\n");
	printf("%s\n",str);

	struct hostent* hp = gethostbyname(str);
	if(hp == NULL)printf("get host by name error!\n");

	int sktid = socket(AF_INET,SOCK_STREAM,0);
	if(sktid == -1)printf("socket error!\n");

	struct sockaddr_in myaddr;
	myaddr.sin_family = AF_INET;
	myaddr.sin_port   = htons(portnum);
	memcpy(&(myaddr.sin_addr),hp->h_addr,hp->h_length);
	//myaddr.sin_addr.s_addr = inet_addr("192.168.13.221");

	int bindid = bind(sktid,(struct sockaddr*)&myaddr,sizeof(myaddr));
	if(bindid == -1)printf("bind error!\n");

	return sktid;
}

void main(){
	int skt_id = create_socket(13000);
	printf("success!\n");
	printf("%d\n",skt_id);


}