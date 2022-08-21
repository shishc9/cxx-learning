#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

typedef struct thread_data {
    int thread_id;
    char *message;
} thread_data;

void *print_hello(void* args) {
    thread_data *my_data;
    my_data = (thread_data*) args;
    cout << "thread id: " << my_data->thread_id;
    cout << "message: " << my_data->message;

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data td[NUM_THREADS];
    int rc;
    int i;

    for (i = 0;i < NUM_THREADS; i++) {
        cout << "main(), create thread id: " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char*)"new message";
        rc = pthread_create(&threads[i], NULL, print_hello, (void*)&(td[i]));
        if (rc) {
            cout << "error: unable to create thread, rc =  " << rc << endl;
            exit(-1);
        }
    } 

    pthread_exit(NULL);
}
