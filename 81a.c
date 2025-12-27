#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* sum_function(void* arg) {
    int n;
    long long sum = 0;

    printf("Enter a number N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        pthread_exit(NULL);
    }

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Summation of first %d natural numbers = %lld\n", n, sum);

    pthread_exit(NULL); 
}

int main() {
    pthread_t tid;

    
    if (pthread_create(&tid, NULL, sum_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    
    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    return 0;
}
