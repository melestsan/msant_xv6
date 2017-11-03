#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]) {
   int status, pid;

   pid = fork();

   if(pid > 0) {
     printf(1, "parent: child=%d\n", pid);
     pid = wait(&status);
     printf(1, "child %d is done. Child's exit status:%d\n", pid, status);
   } else if(pid == 0) {
     printf(1, "child is exiting with 32\n");
     exit(32);
   } else {
     printf(1, "fork error\n");
   }

   //printf(1,"Hello world!\n");
   exit(0);
}
