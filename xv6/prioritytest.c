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
// void prioritytest2() {
// }

int main(int argc, char* argv[]) {
  printf(1, "Starting priority test\n");
  prioritytest1();
  
  exit(0);
}
