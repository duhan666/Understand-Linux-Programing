
#include <sys/time.h>
#include <stdio.h>
#include <signal.h>


int set_timer(int msec){

	int sec    =  msec/1000;
	int u_sec  =  msec%1000*1000L;

	struct itimerval time_val;

	time_val.it_interval.tv_sec = sec;
	time_val.it_interval.tv_usec = u_sec;

	time_val.it_value.tv_sec = 1;
	time_val.it_value.tv_usec = 0;
	
	return setitimer(ITIMER_REAL,&time_val,NULL);
}

void f(int s){
	printf("the timer is triggered!\n");
}

void main(){
	set_timer(3000);
	signal(SIGALRM,f);
	while(1){
		printf("haha\n");
		sleep(1);
	}
}

