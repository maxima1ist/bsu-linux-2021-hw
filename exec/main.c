#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *argv[] = {"bash", "-c", "echo \"psome is $psome\"", NULL};
    char *envp[] = {"psome=some", NULL};

    if (execve("/bin/bash", argv, envp) == -1) {
        fprintf(stderr, "execve call faild\n");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}