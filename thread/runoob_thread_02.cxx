#include <iostream>
#include <pthread.h>
#include <cstdlib>

#define NUM_THREADS 5

void *printArgs(void *thread_id) {
    int tid = *((int*)thread_id);
    std::cout << "say hello! thread_id:" << tid << std::endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int index[NUM_THREADS];
    int rc;
    int i;
    for (i = 0;i < NUM_THREADS; i++) {
        std::cout << "main(): create thread id: " << i << std::endl;
        index[i] = i;
        rc = pthread_create(&threads[i], NULL, printArgs, (void*)&(index[i]));
        if (rc) {
            std::cout << "error code:" << rc << std::endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
}