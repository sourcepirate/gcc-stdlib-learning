#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <error.h>

#define _XOPEN_SOURCE
extern int errno;

int main(void)
{
    int fd=creat("newtext.txt",0777);
    char* msg="hey hello how are you this is some crap in this file so please ignore it\n";
    off_t ret;
    ssize_t bits;
    char* buf;
    close(fd);
    /*O_SYNC flag enables us to open a file in synchronous way i.e sync the read writes files with the buffer.*/
    fd=open("newtext.txt",O_RDWR|O_SYNC);
    if(fd==-1)
        perror("error while opening the file");
    /*seeking is just moving around the file*/
    ret=write(fd,msg,strlen(msg));
    if(ret==-1)
        perror("error while writing");
    ret=lseek(fd,0,SEEK_END);
    if(ret==-1)
        perror("error while seeking");
    printf("%d has moved\n",ret);

    /*POSTITIONAL READS AND WRITES*/
    bits=pread(fd,buf,20,2);
    if(bits==-1)
        perror("error while reading a the give position");
    printf(buf);
    return EXIT_SUCCESS;
}

