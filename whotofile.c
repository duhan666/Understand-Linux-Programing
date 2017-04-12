

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <>

void main(){
	int pid = fork();
	if(pid == 0){
		printf("In Child Process!\n");
		char* str[2] = {"who",NULL};
		close(1);
		int newpid = creat("usrlist",0644);
		if(newpid != 1)
			printf("Creat Error!\n");
		execvp("who",str);
		exit(1);
	}
	else{
		wait(NULL);
		printf("the cmd who is done!\n");
	}

}