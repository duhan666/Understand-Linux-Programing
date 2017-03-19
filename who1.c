
// who1
#include <stdio.h>
//#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	struct utmp current_record;
	int utmpfd;
	int reclen = sizeof(current_record);
	utmpfd = open("/var/run/utmp",O_RDONLY);
	//printf("%d\n",utmpfd);

	if(utmpfd == -1)printf("open file error!\n");

	while(read(utmpfd,&current_record,reclen)==reclen)
		printf("%s\n",current_record.ut_user);

	close(utmpfd);
	return 0;
}