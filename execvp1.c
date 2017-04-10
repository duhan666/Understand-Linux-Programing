
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 20
#define NUMARG 20

void myexec(char* argv[]){
	printf("hahahaha\n");
	int i;
	//for(i=0;i<3l;i++){
	//	printf("%s\n",argv[i]);
	//}
	int c = execvp(argv[0],argv);
	printf("%d\n",c);
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




/*



void main(){
	int counter = 0;
	char *buf;
	char *pstr[];
	while(1){
		fgets(buf,STRLEN,stdio);
		char *cp = malloc(STRLEN);
		strpcy(cp,buf);
		pstr[counter] = 
	}
}*/

/*
void main(){

	int len = 20;
	char* cp = malloc(len+1);
	
	fgets(cp,len,stdin);
	
	printf("%s\n",cp);

}*/