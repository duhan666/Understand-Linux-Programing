
//succeed in redirecting stdin to "/etc/passwd"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define strlength 100

void main(){
	/* close(0)----open() to element redirection
	char str[100];
	fgets(str,strlength,stdin);
	printf("%s\n", str);

	close(0);
	int fd = open("/etc/passwd",O_RDONLY);
	if(fd != 0)printf("The fd is not 0!\n");
	fgets(str,strlength,stdin);
	printf("%s\n", str);
	*/


	// open(fd)---close(0)---dup(fd)----close(fd) to element redir
	char str[100];
	fgets(str,strlength,stdin);
	printf("%s\n", str);

	
	int fd = open("/etc/passwd",O_RDONLY);
	close(0);
	int newfd = dup(fd);
	close(fd);
	if(newfd != 0)printf("The fd is not 0!\n");
	fgets(str,strlength,stdin);
	printf("%s\n", str);
}


