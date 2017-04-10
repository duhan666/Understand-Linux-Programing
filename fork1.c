


#include <unistd.h>
#include <stdio.h>

void main(){
	int retbyfork;
	printf("Beford fork(),PID is %d\n", getpid());

	retbyfork = fork();

	printf("After fork(),PID is %d,fork said it's %d\n",getpid(),retbyfork);

}

