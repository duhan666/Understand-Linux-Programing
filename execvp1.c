
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 20
#define NUMARG 20

void myexec(char* argv[]){
	
	
	int pid = fork();;

	switch(pid){
		case -1:
			printf("Error\n");
			break;
		case  0:
			execvp(argv[0],argv);
			exit(1);
			break;
		default:
			wait(NULL);		
			break;
	}


}



void main(){	
		
	int cnt;
	char *argv[STRLEN];
	cnt = 0;
	while(cnt < NUMARG){

		printf("argv[%d]?\n",cnt);
		char* buf = malloc(STRLEN);
		fgets(buf,STRLEN,stdin);
		if(buf[0] != '\n'){	
			buf[strlen(buf)-1] = '\0';
			argv[cnt] = buf;
			cnt++;
		}
		else{
			argv[cnt] = NULL;
			cnt = 0;
			myexec(argv);
		}
	}

}


