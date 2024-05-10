#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/resource.h>

void sigxcpu_handler(int signum) {
    printf("Received SIGXCPU signal\n");
    exit(EXIT_FAILURE);
}

int main() {
    // Register the signal handler for SIGXCPU
    signal(SIGXCPU, sigxcpu_handler);

    // Set a CPU time limit of 1 second
    struct rlimit cpu_limit;
    cpu_limit.rlim_cur = 1;  // Soft limit of 1 second
    cpu_limit.rlim_max = 1;  // Hard limit of 1 second
    if (setrlimit(RLIMIT_CPU, &cpu_limit) != 0) {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to consume CPU time
    while (1) {
        // Do some CPU intensive task
        for (int i = 0; i < 100000000; ++i) {
            double x = i * i;
        }
    }

    return 0;
}


