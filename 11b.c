#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define MAX_MEALS 3  // Number of meals per philosopher

sem_t room; // Limits the number of philosophers in the room
sem_t chopstick[NUM_PHILOSOPHERS]; // Chopsticks (as semaphores)

void *philosopher(void *num);
void eat(int phil_id);

int main() {
    int i, a[NUM_PHILOSOPHERS];
    pthread_t tid[NUM_PHILOSOPHERS];

    // Initialize room to NUM_PHILOSOPHERS - 1
    sem_init(&room, 0, NUM_PHILOSOPHERS - 1);

    // Initialize chopsticks
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    // Create threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        a[i] = i;
        pthread_create(&tid[i], NULL, philosopher, (void *)&a[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(tid[i], NULL);
    }

    // Cleanup
    sem_destroy(&room);
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&chopstick[i]);
    }

    printf("\nAll philosophers are done eating.\n");
    return 0;
}

void *philosopher(void *num) {
    int phil_id = *(int *)num;

    for (int i = 0; i < MAX_MEALS; i++) {
        printf("Philosopher %d is thinking...\n", phil_id);
        fflush(stdout);
        sleep(rand() % 3 + 1); // Simulate thinking

        // Enter the room
        sem_wait(&room);
        printf("Philosopher %d has entered the room.\n", phil_id);
        fflush(stdout);

        // Pick up left chopstick
        sem_wait(&chopstick[phil_id]);
        printf("Philosopher %d picked up left chopstick %d.\n", phil_id, phil_id);
        fflush(stdout);

        // Pick up right chopstick
        sem_wait(&chopstick[(phil_id + 1) % NUM_PHILOSOPHERS]);
        printf("Philosopher %d picked up right chopstick %d.\n", phil_id, (phil_id + 1) % NUM_PHILOSOPHERS);
        fflush(stdout);

        // Eat
        eat(phil_id);
        sleep(rand() % 2 + 1);

        // Put down right chopstick
        sem_post(&chopstick[(phil_id + 1) % NUM_PHILOSOPHERS]);
        printf("Philosopher %d put down right chopstick %d.\n", phil_id, (phil_id + 1) % NUM_PHILOSOPHERS);
        fflush(stdout);

        // Put down left chopstick
        sem_post(&chopstick[phil_id]);
        printf("Philosopher %d put down left chopstick %d.\n", phil_id, phil_id);
        fflush(stdout);

        // Leave the room
        sem_post(&room);
        printf("Philosopher %d has left the room.\n", phil_id);
        fflush(stdout);

        sleep(rand() % 2 + 1); // Simulate time outside the room
    }

    printf("Philosopher %d is done eating.\n", phil_id);
    fflush(stdout);
    return NULL;
}

void eat(int phil_id) {
    printf("Philosopher %d is eating...\n", phil_id);
    fflush(stdout);
}

