//ls

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

void show_dir(char *dirp);

main(int ac, char *arg[]){

	if(ac == 1)
		show_dir(".");
	else
		while(--ac)
			show_dir(*++arg);
}

void show_dir(char *dirp){
	DIR* dp = opendir(dirp);
	struct dirent* ddp;
	while((ddp = readdir(dp)) != NULL)
		if(ddp->d_name[0]=='.')
			continue;
		else
			printf("%s\t",ddp->d_name);
	printf("\n");
}



