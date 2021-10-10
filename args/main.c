#include "stdio.h"

int main(int argc, char** argv) {
    for (size_t i = 0; i < argc; ++i) {
        printf("arg%ld %s\n", i, argv[i]);
    }

    return 0;
}
