#include "types.h"
#include "stat.h"
#include "user.h"

// mimics wait test but with waitpid instead
// output should not be different
void waitpidtest1() {
    int status, pid;

    pid = fork();

    if(pid > 0) {
	printf(1, "parent: child=%d\n", pid);
	pid = waitpid(pid, &status, 0);
	printf(1, "child %d is done\n", pid);
    } else if(pid == 0) {
	printf(1, "child is exiting\n");
	exit(0);
    } else {
	printf(1, "fork error\n");
    }

    printf(1, "waitpid test 1 okay\n");
}

// waitpidtest2 derived from CS153 HW1 Q4
void waitpidtest2() {
   int status;

   int pid1, pid2, pid3 = 0;
   int i = 3;

   printf(1, "Starting waitpid test\n");

   pid1 = fork();

   if(pid1 > 0)
   {
	printf(1, "%d\n", ++i);
	pid2 = fork();

	if(pid2 > 0) { 
	    if(waitpid(pid1, &status, 0) < 0) {
		printf(1, "waitpid error\n");
		exit(-1);
	    }
	    printf(1, "%d\n", ++i);
	    if(waitpid(pid2, &status, 0) < 0) {
		printf(1, "waitpid error\n");
		exit(-1);
	    }
	    printf(1, "%d\n", ++i);
	} 
	else if(pid2 == 0) 
	{
	    pid3 = fork();

	    if(pid3 > 0) {
		waitpid(pid3, &status, 0);
		printf(1, "%d\n", ++i);
	    } else if(pid3 == 0) {
		printf(1, "%d\n", ++i);
		exit(0);
	    } else {
	        printf(1, "fork error\n");
		exit(-1);
	    }
	} 
	else 
	{ // second fork error
	    printf(1, "fork error\n");
	    exit(-1);
	}
	exit(0);
   } 
   else if(pid1 == 0)
   { 
	printf(1,"%d\n", ++i);
   	exit(0);
   } 
   else
   {
	printf(1, "fork error\n");
	exit(-1);
   }

   printf(1, "waitpid test 2 okay");
}

int main(int argc, char* argv[]) {
    // waitpidtest1();
    waitpidtest2();
    exit(0);
}
