#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep

// Semaphores and mutex
sem_t wrt;               // Controls access for writers (binary semaphore)
pthread_mutex_t mutex;   // Controls access to readercount (mutex)

// Shared data
int readercount = 0;     // Number of active readers
int shared_data = 0;     // Shared resource

// Number of iterations each thread will run (for testing/demo)
#define NUM_ITERATIONS 5

// Function for reader threads
void *reader(void *arg) {
    int reader_id = *((int *)arg);
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Entry section for readers
        pthread_mutex_lock(&mutex);
        readercount++;
        if (readercount == 1) {
            sem_wait(&wrt); // First reader locks writers
        }
        pthread_mutex_unlock(&mutex);

        // Critical section for readers
        printf("Reader %d is reading: shared_data = %d\n", reader_id, shared_data);
        fflush(stdout);
        usleep(rand() % 1000000); // Simulated reading time

        // Exit section for readers
        pthread_mutex_lock(&mutex);
        readercount--;
        if (readercount == 0) {
            sem_post(&wrt); // Last reader unlocks writers
        }
        pthread_mutex_unlock(&mutex);

        usleep(rand() % 2000000); // Simulated time outside critical section
    }
    return NULL;
}

// Function for writer threads
void *writer(void *arg) {
    int writer_id = *((int *)arg);
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Entry section for writers
        sem_wait(&wrt); // Acquire write lock

        // Critical section for writers
        shared_data++; // Modify shared data
        printf("Writer %d is writing: shared_data = %d\n", writer_id, shared_data);
        fflush(stdout);
        usleep(rand() % 1000000); // Simulated writing time

        // Exit section for writers
        sem_post(&wrt); // Release write lock

        usleep(rand() % 3000000); // Simulated time outside critical section
    }
    return NULL;
}

int main() {
    pthread_t reader_threads[5];
    pthread_t writer_threads[2];
    int reader_ids[5];
    int writer_ids[2];

    // Initialize semaphore and mutex
    sem_init(&wrt, 0, 1); // Binary semaphore
    pthread_mutex_init(&mutex, NULL);

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&reader_threads[i], NULL, reader, (void *)&reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writer_threads[i], NULL, writer, (void *)&writer_ids[i]);
    }

    // Join all threads
    for (int i = 0; i < 5; i++) {
        pthread_join(reader_threads[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    // Clean up
    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);

    return 0;
}

