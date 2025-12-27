#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void myHandler(int sig)
{
	printf("\nSignal is received with number:%d\n",sig);
	exit(0);
}
int main()
{
	signal(SIGINT,myHandler);
	while(1){
		printf("My PID is->%d\n",getpid());
		sleep(1);
	}
	return 0;
}
