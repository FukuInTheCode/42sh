#include <stdio.h>

int main() {
    // Define an invalid assembly instruction (UD2)
    asm("ud2");
    
    // This line will only be reached if SIGILL signal is not raised
    printf("This line should not be reached.\n");

    return 0;
}

