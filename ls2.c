	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <time.h>
	#include <string.h>
	#include <pwd.h>
void show_stat_info(char a[],struct stat* buf);
void mode_to_letter(int mode,char* str);

main(int cnt,char* arg[]){
	
	struct stat buf;
	

	if(cnt > 1)
		if(stat(arg[1],&buf)!=-1){
			show_stat_info(arg[1],&buf);
			
			return 0;
		}
		else
			perror("show file Failed:");

	return 1;
}


void mode_to_letter(int mode,char* str){
	strcpy(str,"---------");
	if(S_IXOTH&mode)str[8]='x';
	if(S_IWOTH&mode)str[7]='w';
	if(S_IROTH&mode)str[6]='r';
	if(S_IXGRP&mode)str[5]='x';
	if(S_IWGRP&mode)str[4]='w';
	if(S_IRGRP&mode)str[3]='r';
	if(S_IXUSR&mode)str[2]='x';
	if(S_IWUSR&mode)str[1]='w';
	if(S_IRUSR&mode)str[0]='r';
}



void show_stat_info(char a[],struct stat* buf){
	char str[9];
	mode_to_letter(buf->st_mode,str);
	printf("mode:\t%s\n", str);
	printf("usrN:\t%s\n", getpwuid(buf->st_uid)->pw_name);
	printf("GrpID:\t%d\n", buf->st_gid);
	printf("Size:\t%lld\n", (long long)buf->st_size);
	printf("links:\t%d\n", buf->st_nlink);
	printf("mdtime:\t%s", ctime(&buf->st_mtime)+4);
	printf("time:\t%s", ctime(&buf->st_atime)+4);
	printf("name:\t%s\n", a);
}
	