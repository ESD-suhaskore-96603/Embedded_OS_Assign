#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void do_work(char name) {
    for (int i = 0; i < 5; i++) {
        printf("Process %c (PID: %d, PPID: %d) count: %d\n", name, getpid(), getppid(), i);
        sleep(1);
    }
}

int main() {
    int status;
    printf("Parent A (PID: %d) starting chain...\n", getpid());

    if (fork() == 0) { // Create B
        if (fork() == 0) { // Create C
            if (fork() == 0) { // Create D
                do_work('D');
                exit(0);
            }
            do_work('C');
            wait(&status); // C waits for D
            exit(0);
        }
        do_work('B');
        wait(&status); // B waits for C
        exit(0);
    }

    do_work('A');
    wait(&status); // A waits for B
    printf("Chain complete.\n");
    return 0;
}

