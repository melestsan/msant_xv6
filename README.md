# CS153 xv6 Repo
## Lab 1 Overview
### Part 1: Adding a system call
1. Change exit() to exit(int)
2. Change wait() to wait(int\*)
3. Add waitpid(int,int\*,int)
### Part 2: Implementing priority scheduling 
1. Add setpriority(int)
2. Change scheduler to priority scheduler

## Lab 1 Clarification
 + `exit(int)` - the argument passed into exit updates the process's exitstatus member
 + `wait(int*)` - the pointer gets updated with the exit status of the child.
 + `waitpid(int,int*,int)` - acts like `wait(int*)`, but with additional functionality.
	1. First argument is the pid of the process that the caller wants to wait for
	2. Second argument is a pointer that gets updated with the exit status of the process the caller is waiting for
	3. Third argument represents the options for waitpid
 + `setpriority(int)` - changes the caller's priority value to the passed in argument. If argument is not a valid priority level, function will return -1. It yields once priority is set to make sure highest priority process is running.
 + `scheduler()` - changed from round-robin to priority scheduling. Priority values range from 0 - 63. 0 is the highest.

## Lab 2 Overview
### Part 1: Growing Stack

### Part 2: Implement Shared Memory
