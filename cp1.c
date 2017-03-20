

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 4096
#define CP_MODE 0644

main(int argc,char *arg[]){
	int in_fd,out_fd,c_size;
	char buf[BUFSIZE];

	if((in_fd = open(arg[1],O_RDONLY))==-1)
		printf("Open %s Fail!\n",arg[1]);

	if((out_fd = creat(arg[2],CP_MODE))==-1)
		printf("create %s Fail!\n",arg[2]);

	while((c_size=read(in_fd,buf,BUFSIZE))>0)
		if(write(out_fd,buf,c_size)!=c_size)
			printf("write error to %s\n",arg[2]);
	if(c_size==-1)
		printf("Read from %s error!",arg[1]);
}