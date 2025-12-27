#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"shm_area.h"

int main() {
    int shmid;
    struct shm_area *smem;
    shmid = shmget(KEY, sizeof(struct shm_area), IPC_CREAT | 0666);
    smem = (struct shm_area *) shmat(shmid, NULL, 0);

    shm_init(smem);
    smem->spid = getpid();

    signal(SIGCONT, sigh);
    printf("Server: Waiting for client...\n");

    while (smem->cpid == 0)
        usleep(1000); 

    printf("Server: Connected to client PID %d\n", smem->cpid);

    pause(); 
    printf("Server: Received string '%s'\n", smem->data);
    	int len = strlen(smem->data);
        int flag = 1;
        	for (int i = 0; i < len / 2; i++) {
                	if (smem->data[i] != smem->data[len - i - 1]) {
                    	flag = 0;
                    	break;
                	}
            	}
            	smem->result = flag;
            	printf("Server: Sending result (%d) back to client...\n", flag);
            	kill(smem->cpid, SIGCONT);
  		shmdt(smem);
    		return 0;
}

