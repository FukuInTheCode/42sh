#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    // Create a pipe
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Close the read end of the pipe
    close(pipe_fd[0]);

    // Attempt to write to the closed pipe
    if (write(pipe_fd[1], "Hello", 5) == -1) {
        perror("write");
        // Note: write will return -1 and set errno to EPIPE when the pipe is broken
    }

    return 0;
}


