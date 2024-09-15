/*
============================================================================
Name : 6.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a simple program to create three threads.
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* my_thread(void* arg) {
    printf("Hello from thread %ld\n", (long)arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    for (int i=0; i<3; i++) {
        if (pthread_create(&threads[i], NULL, my_thread, (void*)(long)i) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i=0; i<3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
Output:
$ gcc 6_b.c -pthread
$ ./a.out 
Hello from thread 0
Hello from thread 1
Hello from thread 2
*/