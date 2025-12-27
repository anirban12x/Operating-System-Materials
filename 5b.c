#include <stdio.h>
#include <unistd.h>

int main() {
	int p = fork();
	if (p<0){
		printf("Error");
	}
	else if(p==0) {
		printf("Child: PID: %d, PPID %d\n", getpid(), getppid());
		sleep(20);
	
	}
	else {
		printf("Parent: PID: %d, PPID: %d\n", getpid(), getppid());
		sleep(10);
		printf("Parent Died\n");
	}
	
	return 0;
}
