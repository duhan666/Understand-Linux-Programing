//

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


/*
struct stat {
    dev_t     st_dev;      ID of device containing file 
    ino_t     st_ino;      inode number 
    mode_t    st_mode;     protection 
    nlink_t   st_nlink;    number of hard links 
    uid_t     st_uid;      user ID of owner 
    gid_t     st_gid;      group ID of owner 
    dev_t     st_rdev;     device ID (if special file) 
    off_t     st_size;     total size, in bytes 
    blksize_t st_blksize;  blocksize for filesystem I/O 
    blkcnt_t  st_blocks;   number of 512B blocks allocated 
    time_t    st_atime;    time of last access 
    time_t    st_mtime;    time of last modification 
    time_t    st_ctime;    time of last status change 
    };  

struct dirent {
    ino_t          d_ino;        inode number 
    off_t          d_off;        not an offset; see NOTES 
    unsigned short d_reclen;     length of this record 
    unsigned char  d_type;       type of file; not supported
                                 by all filesystem types 
    char           d_name[256];  filename 
};

*/


ino_t getinum(char* str){
    struct stat* f_stat = malloc(sizeof(struct stat));
    if(f_stat == NULL)
        return 0;
    stat(str,f_stat);
    ino_t c = f_stat->st_ino;
    free(f_stat);
    return c;
}


char* get_cur_filename(ino_t ino,char* str){
    DIR* fp = opendir(str);
    //char s[512];
    //s[0]='\0';
    struct dirent* dir = malloc(sizeof(struct dirent));
    while((dir = readdir(fp))!=NULL)
        if(dir->d_ino==ino)
            return dir->d_name;
}

void printdir1(){
    while(getinum(".") != getinum("..")){
        ino_t c = getinum(".");
        char* str = get_cur_filename(c,"..");
        printf("/%s",str );
        chdir("..");
    }
    printf("\n");
}

void printdir(char* s){
    if(getinum(".") != getinum(".."))
        printdir("..");
    ino_t w = getinum(".");
    char* str = get_cur_filename(w,".");
    printf("%s/\n",str );
}


main(){
    //ino_t w = getinum(".");
    //char* str = get_cur_filename(w,"..");
    //printf("%s\n",str );
    printdir(".");
}