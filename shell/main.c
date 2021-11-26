#include "Runner.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1024
#define ARGS_SIZE 100
#define ARG_LENGHT 20
#define PATH "/bin/"

int main() {
    char* line = (char*) malloc(LINE_SIZE * sizeof(char));
    char* command = (char*) malloc(ARG_LENGHT * sizeof(char));
    char* program = (char*) malloc((ARG_LENGHT + sizeof(PATH)) * sizeof(char));

    char** args = (char**) malloc(ARGS_SIZE * sizeof(char*));
    for (size_t i = 0; i < ARGS_SIZE ; ++i) {
        args[i] = (char*) malloc(ARG_LENGHT * sizeof(char));
    }

    while (1) {
        size_t argsCount = 0;

        printf("$ ");
        
        if (fgets(line, sizeof line, stdin) == NULL) {
            break;
        }

        char* unit = strtok(line, " \n");
        if (unit != NULL) {
            strcpy(command, unit);
            if (!strncmp(command, "exit", (strlen(command) - 1))) {
                break;
            }
        }

        while (unit != NULL) {
            strcpy(args[argsCount++], unit);
            unit = strtok(NULL, " \n");
        }
        
        if (argsCount == 0) {
            continue;
        }

        free(args[argsCount++]);
        args[argsCount - 1] = NULL;

        strcpy(program, PATH);
        strcat(program, command);

        run(program, args);

        args[argsCount - 1] = (char*) malloc(ARG_LENGHT * sizeof(char));
    }

    for (size_t i = 0; i < ARGS_SIZE ; ++i) {
        free(args[i]);
    }
    free(args);

    free(line);
    free(command);
    free(program);
    
    exit(EXIT_SUCCESS);
}