
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void main(){
	int fd[2];

	char buf[50];
	pipe(fd);
	printf("%d\t%d\n",fd[0],fd[1]);
	int pid = fork();
	if(pid > 0){
		char s[] = "hello world!";
		int len = strlen(s);
		write(fd[1],s,len);
	}
	else if(pid == 0){
		read(fd[0],buf,40);
		printf("%s\n",buf);
	}

}