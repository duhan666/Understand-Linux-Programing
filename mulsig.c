#include <stdio.h>
#include <signal.h>

#define INPUTLEN 100

void inthandler(int s){
	printf("Received signal %d..waiting\n",s);
	sleep(3	);
	printf("Leaving inthandler\n");
}

void quithandler(int s){
	printf("Received signal %d..waiting\n",s);
	sleep(4);
	printf("Leaving quithandler\n");
}

void main(){
	signal(SIGINT,inthandler);
	signal(SIGQUIT,quithandler);

	char str[INPUTLEN];
	int c = 1;
	while(strncmp(str,"quit",4)!=0){
		c = read(0,str,INPUTLEN-1);

		str[c] = '\0';
		printf("%s\n",str);
	}

}

