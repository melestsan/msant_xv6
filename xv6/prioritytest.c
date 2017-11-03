#include "types.h"
#include "stat.h"
#include "user.h"

// Basic verfication that setpriority works
void prioritytest1() {
  
  // valid input
  if(setpriority(2) < 0) {
    printf(1, "set priority error\n");
    exit(-1);
  }

  // input too high
  if(setpriority(64) < 0) {
    printf(1, "expected error, okay\n");
  } else {
    printf(1, "set priority error\n");
    exit(-1);
  }

  // input too low
  if(setpriority(-1) < 0) {
    printf(1, "expected error, okay\n");
  } else {
    printf(1, "set priority error\n");
    exit(-1);
  }

  printf(1, "prioritytest1 okay\n");
}

// Testing that scheduler switches to proc
// with the highest priority
void prioritytest2() {
  int pidc1, pidc2, pidCheck, status;

  pidc1 = fork();

  if(pidc1 > 0) {
    pidc2 = fork();
    if(pidc2 > 0) {
      pidCheck = wait(&status);
      printf(1, "child:%d just finished!\n", pidCheck);
      pidCheck = wait(&status);
      printf(1, "child:%d just finished!\n", pidCheck);
    } else if(pidc2 == 0) {
      setpriority(2);
      printf(1, "I'm child %d. My priority is set to 2! I should finish first!\n", getpid());  
      exit(0);
    } else {
      printf(1, "fork error\n");
      exit(-1);
    }
  } else if(pidc1 == 0) {
    setpriority(40);
    printf(1, "I'm child:%d. My priority is set to 40! I should after my sibling, but before my parent!\n", getpid());  
    exit(0);
  } else {
    printf(1, "fork error\n");
    exit(-1);
  }

  printf(1, "prioritytest2 okay\n");
}

int main(int argc, char* argv[]) {
  printf(1, "\nStarting priority test\n");
  
  if(atoi(argv[1]) == 1)
    prioritytest1();
  else if(atoi(argv[1]) == 2)
    prioritytest2();
  else
    printf(1, "to test type \"setpriority #\"");  

  exit(0);
}
