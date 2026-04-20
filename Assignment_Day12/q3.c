#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int count = 0;
    
    while(1) {
        int ret = fork();

        if(ret < 0) {
            // Fork failed: we hit the system limit
            printf("\nReached limit! Max processes: %d\n", count);
            break; 
        }
        else if(ret == 0) {
            // CHILD: Stay alive so the parent can count you
            // But DO NOT loop. We use sleep and then exit.
            sleep(100); 
            exit(0); 
        }
        else {
            // PARENT: Increment count and keep forking
            count++;
            if(count % 100 == 0) {
                printf("Processes created: %d\r", count);
                fflush(stdout);
            }
        }
    }
    return 0;
}
        
