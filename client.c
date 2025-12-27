#include "shm_area.h"

int main() {
    int shmid;
    struct shm_area *smem;
    char input[DATASIZE];
    shmid = shmget(KEY, sizeof(struct shm_area), IPC_CREAT | 0666);
    smem = (struct shm_area *) shmat(shmid, NULL, 0);
    smem->cpid = getpid();

    while (smem->spid == 0)
        usleep(1000);
        
    printf("Client: Enter a string: ");
    scanf("%s", input);

    strcpy(smem->data, input);

    signal(SIGCONT, sigh);
    kill(smem->spid, SIGCONT);
    
    pause();


        if (smem->result == 1)
            printf("Client: '%s' is a PALINDROME.\n", input);
        else
            printf("Client: '%s' is NOT a palindrome.\n", input);
    shmdt(smem);
    return 0;
}


   
   
