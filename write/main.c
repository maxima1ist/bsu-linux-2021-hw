#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main (int argc, char *argv[]) {

    size_t write_times = 1;
    int32_t fd = 1;
    char *buf = "Hello, world\n";

    const char* short_options = "n:d:";

    const struct option long_options[] = {
        {"descriptor", required_argument, NULL, 'd'},
        {NULL, 0, NULL, 0}
    };

    int32_t rez;
    int32_t option_index = -1;
    
    while ((rez = getopt_long(argc,
                              argv,
                              short_options,
                              long_options,
                              &option_index)) != -1) {
        switch(rez) {
            case 'n': {
                write_times = (size_t)atoi(optarg);
                break;
            }
            case 'd': {
                fd = atoi(optarg);
                break;
            }
            case '?': default: {
                printf("found unknown option\n");
                break;
            }
        }
        option_index = -1;
    }

    // means that last arg is position argument
    if (optind == argc - 1) {
        buf = argv[optind];
    }

    for (size_t i = 0; i < write_times; ++i) {
        write(fd, buf, strlen(buf));
    }

    return 0;
}
