//temp

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
	char str[100];
	gethostname(str,100);
	printf("%s\n",str);
}