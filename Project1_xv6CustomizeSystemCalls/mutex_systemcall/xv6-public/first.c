#include "types.h"
#include "stat.h"
#include "user.h"
#include "mutex.h"

uint m;
int x = 10;
int *counter = &x;

int main() {
    mutex_init(&m);

    if(fork() == 0){ // Child process (Producer)
        for(int i=0;i<5;i++){
            mutex_lock(&m);
            printf(1, "Child (Producer) acquired lock, counter val = %d\n", *counter);
            *counter = *counter + 1;
            printf(1, "Child incremented counter, new val = %d\n", *counter);
            mutex_unlock(&m);
            printf(1, "Child released lock\n");
            sleep(50); // Simulate some work
        }
        exit();
    }else{ // Parent process (Consumer)
        for(int i = 0; i < 5; i++){
            sleep(25); // Offset to allow child to run first
            mutex_lock(&m);
            printf(1, "Parent (Consumer) acquired lock, counter val = %d\n", *counter);
            *counter = *counter - 1;
            printf(1, "Parent decremented counter, new val = %d\n", *counter);
            mutex_unlock(&m);
            printf(1, "Parent released lock\n");
            sleep(50); // Simulate some work
        }
        wait(); // Wait for the child to finish
    }
    printf(1, "Final counter value = %d\n", *counter);
    exit();
}
