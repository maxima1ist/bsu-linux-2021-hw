#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#define N 100
#define M 200

void dumbSwapStr() {
    char str[2 * M];
    for (size_t i = 0; i < M; ++i) {
        char temp = str[i];
        str[i] = str[2 * M - i - 1];
        str[2 * M - i - 1] = temp;
    }
}

int main() {
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    int start_time = current_time.tv_usec;

    for (size_t i = 0; i < N; ++i) {
        dumbSwapStr();
    }

    gettimeofday(&current_time, NULL);
    int end_time = current_time.tv_usec;

    printf("non syscalls time is %d micro seconds\n", end_time - start_time);

    return 0;
}
