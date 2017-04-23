//temp

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
       #include <sys/types.h>          /* See NOTES */
       #include <sys/socket.h>
#include <netdb.h>


void main(){
	char awp[30];
	gethostname(awp,30);

	struct hostent *hp;

	hp = gethostbyname(awp);



	printf("%s\n",hp->h_addr);
}


