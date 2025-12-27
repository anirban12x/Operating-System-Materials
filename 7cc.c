#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


int isLeapYear(int y) {
    if (y <= 0)
        return 0;
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

void checkLeapYear(int sig) {
    int year;

    printf("\nChild: Received signal from parent (SIGALRM)\n");
    printf("Child: Enter a year:\n");
    scanf("%d", &year);

    if (year <= 0) {
        printf("Child: %d is NOT a valid year\n", year);
    } else if (isLeapYear(year)) {
        printf("Child: %d is a Leap Year\n", year);
    } else {
        printf("Child: %d is NOT a Leap Year\n", year);
    }

    printf("Child: Waiting for the next signal...\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        signal(SIGALRM, checkLeapYear);
        printf("Child: Ready and waiting for SIGALRM from parent...\n");
        while (1) pause();   
    }
    else {
       
        printf("Parent: I will send SIGALRM to child every 5 seconds.\n");
        printf("Parent: Press Ctrl+C to stop the program.\n");

        while (1) {
            sleep(5);
            printf("\nParent: Sending SIGALRM to child...\n");
            kill(pid, SIGALRM);
        }

        wait(NULL); 
        printf("Parent: Child exited. Parent also stopping.\n");
    }

    return 0;
}
