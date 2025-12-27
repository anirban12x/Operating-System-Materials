#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){
	int fd1 = open("fifo1", O_RDONLY);
	int fd2 = open("fifo2", O_WRONLY);
	char str1[100],str2[100], res[20];

	read(fd1, str1, sizeof(str1));
	read(fd1, str2, sizeof(str2));
	if(strcmp(str1,str2)==0){
		strcpy(res,"SAME");
	}
	else{
		strcpy(res,"NOT SAME");
	}
	write(fd2,res,strlen(res)+1);

	close(fd1);
	close(fd2);
	return 0;
}

