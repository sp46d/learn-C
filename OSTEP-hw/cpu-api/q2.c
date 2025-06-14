// Question 2:
// Write a program that opens a file (with the open() system call) and then
// calls fork() to create a new process. Can both the child and parent access
// the file descriptor returned by open()? What happens when they are writing to
// the file concurrently, i.e., at the same time?

// Answer:
// Yes, both child and parent processes can access the file descriptor returned
// by open(). Writing something from either process to the same file descriptor
// is allowed, resulting in both contents written to the same file referenced by
// the file descriptor, although the order of contents may differ depending on
// the order of the processes being executed.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_s_ifmt.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    int fd = open("./q2.output", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child process
        write(fd, "Hello World!\n", 13);
    } else {
        // parent process
        write(fd, "foo bar\n", 8);
    }
    close(fd);
    return 0;
}
