#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int rv = 0;
    int status;
    printf("PARENT: PID -- %d\n", getpid());
    printf("PARENT: parent PID -- %d\n", getppid());

    switch (pid = fork()) {
    case -1:
        perror("fork");
        exit(1);
    case 0:
        printf("CHILD: PID -- %d\n", getpid());
        printf("CHILD: parent PID -- %d\n", getppid());
        exit(rv);
    default:
        printf("PARENT: PID -- %d\n", getpid());
        printf("PARENT: child PID %d\n", pid);
        printf("PARENT: waiting for child exit() call...\n");
        wait(&status);
        printf("PARENT: child return status: %d\n", WEXITSTATUS(rv));
    }

    return 0;
}
