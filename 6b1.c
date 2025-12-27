#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	mkfifo("./fifo1",0666);
	mkfifo("./fifo2",0666);
	char str1[100], str2[100], res[20];
	int fd1 = open("fifo1", O_WRONLY);
	int fd2 = open("fifo2", O_RDONLY);

	printf("Enter the first string: ");
	fgets(str1,sizeof(str1),stdin);
	printf("Enter the second String: ");
	fgets(str2,sizeof(str2),stdin);
	
	write(fd1,str1,strlen(str1)+1);
	write(fd1,str2,strlen(str2)+1);
	
	read(fd2,res,sizeof(res));
	printf("Comparison result: %s\n", res);

	close(fd1);
	close(fd2);
	return 0;
}

