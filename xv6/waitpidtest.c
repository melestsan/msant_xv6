#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]) {
   int pid;
   int status = 1;

   pid = fork();   

   if(!pid) {
	//if(waitpid(pid, &status, 0) < 0) {
	//	printf(1, "Whoa something happened.");
	//	exit(-1);
	//}
	printf(1," Child PID: %d\n", pid);
	exit(0);
   }

   waitpid(0, &status, 0);
   
   printf(1, "Parent PID: %d \n", pid);
   
   exit(0);
}
