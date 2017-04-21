
#include <stdio.h>
#include <pthread.h>

#define NUM 10


// the third argv of pthread_create(): void *(*start_routine)(void*)
int counter = 0;

void main(){

	

	pthread_t t;

	void *msg_print(void *);

	pthread_create(&t,NULL,msg_print,(void*)"hello");

	while(counter<NUM){
		counter++;
		sleep(1);
	}
	pthread_join(t,NULL);

}

void *msg_print(void* str){
	int i;
	for(i=0;i<NUM;i++){
		printf("%s\n",(char*)str);
		//fflush(stdout);
		printf("%d\n",counter);
		sleep(1);
	}
}


