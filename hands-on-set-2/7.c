/*
============================================================================
Name : 7.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a simple program to print the created thread ids.
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* my_thread(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID for thread %ld is %ld\n",(long)arg, (long)tid);
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
$ gcc 7.c -pthread
$ ./a.out 
Thread ID for thread 0 is 139912665888448
Thread ID for thread 2 is 139912649103040
Thread ID for thread 1 is 139912657495744
*/