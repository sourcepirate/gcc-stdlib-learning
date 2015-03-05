#include <stdio.h>
#include <sys/poll.h>
#include <unistd.h>

#define TIMEOUT 5
/*
 * Polled IO is similar to multipled IO using select and pselect except is solves
 * several complexities in MUXIO
 */
int main(void)
{
  /*
   In this example will use standerd input and standard output
  */
   struct pollfd fds[2];
   int ret;

   fds[0].fd=STDIN_FILENO;
   fds[0].events=POLLIN;

   fds[1].fd=STDOUT_FILENO;
   fds[1].events=POLLOUT;

   /*All set, block*/
   ret= poll(fds,2,TIMEOUT*1000);

   if(ret==-1){
       perror("poll");
       return 1;
   }
   if(!ret){
      printf("%d seconds elapsed",TIMEOUT);
      return 0;
   }

   if(fds[0].revents & POLLIN){
       printf("stdin is readable\n");
   }
   if(fds[1].revents & POLLOUT){
       printf("stdout is writable\n");
   }
   return 0;
}

/*
* ./main <"somefile"
*/

