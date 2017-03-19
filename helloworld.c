/*
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	struct utmp current_record;
	int utmpfd;
	int reclen = sizeof(current_record);
	utmpfd = open("/var/run/utmp",O_RDONLY);
	printf("%d\n",utmpfd);
}*/
#include <stdio.h>
void main(){
	printf("hello world!");
}