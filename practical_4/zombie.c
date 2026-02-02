#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        sleep(10);   // Parent wait nahi kar raha
        printf("Parent process\n");
    } else {
        printf("Child process exiting\n");
    }
    return 0;
}

