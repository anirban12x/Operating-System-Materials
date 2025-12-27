#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


void myHandler(int sig)
{
	printf("Ding!\n");
}
int main()
{
	int pid;
	printf("alarm application starting\n");
	pid=fork();
	if(pid==0)
	{
		sleep(2);
		kill(getppid(), SIGALRM);
		exit(0);
	}
	else
	{
		printf("Parent process waiting for alarm to go off\n");
		signal(SIGALRM, myHandler);
		pause();
		printf("done\n");
		exit(0);
	}
}
