
#include <curses.h>

#define L_EDGE    10
#define R_EDGE    15
#define TOP       10	
#define BOTTOM    18


void main(){
	char message[] =  "Hello!";
	char blank[]   =  "       ";
	int  h_dir       =  1;
	int  v_dir       =  1;
	int  h_pos     =  L_EDGE;
	int  v_pos     =  TOP;

	initscr();
	clear();

	while(1){
		move(h_pos,v_pos);
		addstr(message);
		//move(LINES-1,COLS-1);
		refresh();
		usleep(200000);
		move(h_pos,v_pos);
		addstr(blank);
		h_pos+=h_dir;
		v_pos+=v_dir;

		if(h_pos >= R_EDGE)
			h_dir = -1;
		if(h_pos <= L_EDGE)
			h_dir = +1;
		if(v_pos >= BOTTOM)
			v_dir = -1;
		if(v_pos <= TOP)
			v_dir = +1;
	}
}


