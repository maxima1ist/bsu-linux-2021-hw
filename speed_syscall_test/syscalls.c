#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#define N 100

int main() {

  	struct timeval current_time;

  	gettimeofday(&current_time, NULL);
  	int start_time = current_time.tv_usec;

	for (size_t i = 0; i < N; ++i) {
		write(1, "", 0);
	}

  	gettimeofday(&current_time, NULL);
  	int end_time = current_time.tv_usec;

  	printf("syscalls time is %d micro seconds\n", end_time - start_time);


    return 0;
}