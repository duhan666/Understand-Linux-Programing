//temp

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
	char*argv[] = {"ls","-l",NULL};
	execvp(argv[0],argv);
}