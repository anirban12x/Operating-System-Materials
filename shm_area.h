#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define KEY 1234
#define DATASIZE 100

struct shm_area {
    pid_t spid;  
    pid_t cpid;   
    char data[DATASIZE];
    int result;  
};

void shm_init(struct shm_area *smem) {
    smem->spid = 0;
    smem->cpid = 0;
    return;
}
void sigh(int signum){
	static int sigrev = 1;
	return;
}
