
#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <curses.h>

#define TOP 10
#define BOTTOM 40
#define L_EDGE 10
#define R_EDGE 50
#define BLANK ("           ")
#define HELLO ("HE")

	int h_pos = L_EDGE;
	int v_pos = TOP;

	int  delay = 500;
	int h_dir = 1;
	int v_dir = 1; 
	int temp_h;
	int temp_v;

int set_timer(int msec){

	int sec    =  msec/1000;
	int u_sec  =  msec%1000*1000L;

	struct itimerval time_val;

	time_val.it_interval.tv_sec = 1;
	time_val.it_interval.tv_usec = 0;

	time_val.it_value.tv_sec = sec;
	time_val.it_value.tv_usec = u_sec;
	
	return setitimer(ITIMER_REAL,&time_val,NULL);
}

void f(int);

void main(){
	initscr();
	crmode();
	noecho();
	clear();

	move(h_pos,v_pos);
	addstr(HELLO);
	set_timer(500);

	signal(SIGALRM,f);

	int c ;
	while((c=getchar())!=EOF){
		
		switch(c){
			case 's' : delay = delay*2+1;break;
			case 'f' : delay = delay/2+1;break;
			case ' ' : v_dir = -v_dir;h_dir = -h_dir;break;
			default  : break;
		}
		printf("%d\n", delay);
	}
	
}

void f(int s){

	signal(SIGALRM,f);
	move(temp_h,temp_v);
	addstr(BLANK);
	move(h_pos,v_pos);
	temp_h = h_pos;
	temp_v = v_pos;
	addstr(HELLO);
	refresh();
	set_timer(delay);
	h_pos = h_pos + h_dir;
	v_pos = v_pos + v_dir;
	if(h_pos>R_EDGE || h_pos<L_EDGE)
		h_dir = -h_dir;
	if(v_pos<TOP || v_pos>BOTTOM)
		v_dir = -v_dir;
	//printf("%d\t%d\n",h_pos,v_pos );
}
