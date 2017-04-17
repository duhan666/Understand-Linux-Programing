//temp

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
       #include <sys/types.h>          /* See NOTES */
       #include <sys/socket.h>


void main(){
	time_t td = time(NULL);
	printf("%s\n",ctime(&td));
}


