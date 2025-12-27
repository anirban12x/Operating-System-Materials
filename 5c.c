#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int p = fork();
	if (p<0){
		printf("Error");
	}
	else if(p==0) {
		printf("Child: PID: %d, PPID %d\n", getpid(), getppid());
		sleep(10);
		printf("Child Died\n");
	}
	else {
		printf("Parent: PID: %d, PPID: %d\n", getpid(), getppid());
		sleep(20);
		wait(NULL);
	}
	
	return 0;
}
