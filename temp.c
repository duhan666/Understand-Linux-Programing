//temp

#include <time.h>
#include <stdio.h>

void main(){
	int c;
	int delay=500;
while((c=getchar())!=EOF){
		
		switch(c){
			case 's' : delay = delay/2;break;
			case 'f' : delay = delay*2;break;
			//case ' ' : { v_dir = -v_dir;h_dir = -h_dir;};
			default  : break;
		}
		printf("%d\n",delay);
	}
}