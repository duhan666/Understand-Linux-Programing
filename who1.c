
// who1
#include <stdio.h>
//#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void showinfo(struct utmp* utmpfd){
	if(utmpfd->ut_type!=USER_PROCESS)
		return;

	printf("%-8.8s\t",utmpfd->ut_user);
	printf("%-8.8s\t",utmpfd->ut_line);
	long time = utmpfd->ut_time;
	char*s = ctime(&time);
	printf("%s",s+4);
	//printf("\n");
}

int main(){
	struct utmp current_record;
	int utmpfd;
	int reclen = sizeof(current_record);
	utmpfd = open("/var/run/utmp",O_RDONLY);
	//printf("%d\n",utmpfd);

	if(utmpfd == -1)printf("open file error!\n");

	while(read(utmpfd,&current_record,reclen)==reclen)
		showinfo(&current_record);
		

	close(utmpfd);
	return 0;
}