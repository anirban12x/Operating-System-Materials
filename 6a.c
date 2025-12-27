#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
	char read_str[100], write_str[100];
	int fd[2];
	
	pipe(fd); 
	
	int pid = fork();
	if(pid == 0){
		printf("Child Process...\n");
		printf("Enter your String: ");
		fgets(write_str,sizeof(write_str),stdin);
		write(fd[1],(void*)write_str,strlen(write_str)+1);
		
	}
	else{
		
		read(fd[0],(void*)read_str, sizeof(read_str));
		printf("String received from child process: %s", read_str);
		
	}
}
