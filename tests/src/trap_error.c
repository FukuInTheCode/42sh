#include <stdio.h>

int main() {
    // Define an invalid assembly instruction (INT 3)
    asm("int $0x03");
    
    // This line will only be reached if SIGILL signal is not raised
    printf("This line should not be reached.\n");

    return 0;
}

