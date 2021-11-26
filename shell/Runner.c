#include "Runner.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void run(const char* const program, char** const args) {
    int pid;
    int rv = 0;
    switch (pid = fork()) {
    case -1:
        perror("fork failed");
        exit(EXIT_FAILURE);
    case 0:
        dup2(open("Runner.log", O_CREAT | O_APPEND | O_WRONLY), 1);
        execv(program, args);
        exit(rv);
    default:
        wait(NULL);
        printf("return status: %d\n", WEXITSTATUS(rv));
    }
}