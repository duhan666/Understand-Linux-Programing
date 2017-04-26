


#include "webserlib.c"

void main(){
	int conid = create_connect(13000);
	if(conid == -1){
		printf("create_connect error!\n");
	}
	else
		printf("connect OK\n");
}