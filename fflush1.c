
#include <stdio.h>


//this program is not right!!

void main(){
	char c;
	while((c = getchar()) !='Q' ){
		printf("%c\n",c);
		fflush(stdin);
		printf("call getchar once!\n");
	}
}