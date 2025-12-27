#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void* find_primes(void *arg) {
    int *range = (int *)arg;
    int start = range[0];
    int end = range[1];

    printf("Thread handling range %d to %d: ", start, end);

    for (int num = start; num <= end; num++) {
        if (num < 2) continue;
        int isPrime = 1;
        for (int i = 2; i <= num/2; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", num);
        }
    }
    printf("\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    int ranges[10][2];
    int start = 1;
    int step = 100 / 10;


    for (int i = 0; i < 10; i++) {
        ranges[i][0] = start;
        ranges[i][1] = start + step - 1;
        start += step;
    }

    
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, find_primes, (void *)ranges[i]);
        
    }

    
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
