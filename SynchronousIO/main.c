#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <error.h>

extern int errno;

int main(void)
{
    int fd=creat("newtext.txt",0777);
    char* msg="hey hello how are you\n";
    off_t ret;
    close(fd);
    /*O_SYNC flag enables us to open a file in synchronous way i.e sync the read writes files with the buffer.*/
    fd=open("newtext.txt",O_WRONLY|O_SYNC);
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
    return EXIT_SUCCESS;
}

