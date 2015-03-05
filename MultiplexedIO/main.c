/*
*
*  Please Wait for TimeOut seconds as this program block the i/o of file for Timeout seconds after it goes to sleep.
*  Example taken from book LINUX SYSTEM PROGRAMMING
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main(void)
{
  struct timeval tv;
  fd_set readers;
  int ret;

  FD_ZERO(&readers);
  FD_SET(STDIN_FILENO,&readers);

  /*wait up to five seconds*/
  tv.tv_sec=TIMEOUT;
  tv.tv_usec=0;

  ret=select(STDIN_FILENO+1,&readers,NULL,NULL,&tv);
  if(ret==-1)
  {
      perror("select");
      return 1;
  }
  else{
      return 0;
  }
 /*
  * Is something ready for I/O
  */
  if(FD_ISSET(STDIN_FILENO,&readers)){
    char buf[BUF_LEN+1];
    int len;
    len=read(STDIN_FILENO,buf,BUF_LEN);
    if(len==-1){
        perror("read");
        return 1;
    }
    if(len){
        buf[len]='\0';
        printf("%s read:",buf);
    }
    return 0;
  }

  fprintf(stderr,"This should not happen");
  return 1;
}

