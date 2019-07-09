# CS153 xv6 Repo
## Lab 1 Overview
### Part 1: Adding a system call
1. Change `exit()` to `exit(int)`
  + the argument passed updates the process's exit status
2. Change `wait()` to `wait(int\*)`
  + the pointer gets updated with the exit status of the child
3. Add `waitpid(int,int\*,int)`
  + acts like `wait(int*)`, but with additional functionality.
    1. First argument is the pid of the process that the caller wants to wait for
	2. Second argument is a pointer that gets updated with the exit status of the process the caller is waiting for
	3. Third argument represents the options for waitpid
### Part 2: Implementing priority scheduling 
1. Add `setpriority(int)`
  + changes the caller's priority value to the passed in argument. If argument is not a valid priority level, function will return -1. It yields once priority is set to make sure highest priority process is running.
2. Change scheduler to priority scheduler
  + changed from round-robin to priority scheduling. Priority values range from 0 - 63. 0 is the highest.

## Lab 2 Overview
### Part 1: Growing Stack
+ Pages are now mapped below `KERNBASE`. Pointer points to bottom of the page. Allows stack to grow downwards. Added cases for page faults in `trap.c`.
### Part 2: Implement Shared Memory
+ Implemented memory that can be shared among other processes. 
