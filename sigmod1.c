
#include <stdio.h>
#include <signal.h>
#include <time.h>

main(){
	void f(int);
	int i;
	signal(SIGINT,SIG_IGN);
	for(i=0;i<50;i++){
		printf("hello!\n");
		sleep(1);
	}

	
}

void f(int how){
	printf("OUCH\n");
}