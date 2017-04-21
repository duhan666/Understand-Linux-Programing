
#include <stdio.h>
#include <pthread.h>
#include <ctype.h>


int counter = 0;

int main(int argc, char *argv[]){

	pthread_t t1,t2;
	void* w_count(void*);

	//w_count((void*)argv[1]);
	pthread_create(&t1,NULL,w_count,(void*)argv[1]);
	pthread_create(&t2,NULL,w_count,(void*)argv[2]);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("%d\n",counter);
}

void *w_count(void* path){

	char *Path =(char*) path;
	FILE *fp = fopen(Path,"r");
	int c,prev = '\0';
	
	if(fp!=NULL){
		
		while((c=getc(fp))!=EOF){
			if(!isalnum(c)&&isalnum(prev)){
			counter++;
			//printf("here\n");
			}
			prev = c;
		}		
		fclose(fp);
	}
	else {
		printf("open file error,please check path.\n");
	}

	//return counter;

}



