#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* sum_function(void* arg) {
    int n = *(int*)arg;   
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    
    int* result = malloc(sizeof(int));
    if (result == NULL) {
        perror("malloc");
        pthread_exit(NULL);
    }
    *result = sum;

    pthread_exit((void*)result); 
}

int main() {
    pthread_t tid;
    int n;

    printf("Enter a number N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    
    if (pthread_create(&tid, NULL, sum_function, &n) != 0) {
        perror("pthread_create");
        return 1;
    }

    
    int* result;
    if (pthread_join(tid, (void**)&result) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Summation of first %d natural numbers = %d\n", n, *result);

    free(result); 
    return 0;
}
