// Question 1:
// Write a program that calls fork(). Before calling fork(), have the main
// process access a variable (e.g., x) and set its value to something (e.g.,
// 100). What value is the variable in the child process? What happens to the
// variable when both the child and parent change the value of x?

// Answer:
// The child process can access the value of a variable that's declared before
// the fork() call, like a normal program. However, changing its value inside
// the child process won't affect the parent process. Likewise, changing the
// value of a variable from inside the parent process won't affect the child
// process. It seems like they can't communicate with each other.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child process
        // x = 10;
        printf("(child) x: %d\n", x);
    } else {
        // parent process
        x = 1000;
        printf("(parent) x: %d\n", x);
    }
    return 0;
}
