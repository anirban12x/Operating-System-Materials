#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
sem_t mutex;

void *t1(void *arg){
	for(int i=0; i<3; i++){
		sem_wait(&mutex);
		printf("ba");
		sem_post(&mutex);
		usleep(2000);
	}
	pthread_exit(NULL);
}
void *t2(void *arg){
	for(int i=0; i<3; i++){
		sem_wait(&mutex);
		printf("ab");
		sem_post(&mutex);
		usleep(2000);
	}
	pthread_exit(NULL);

}
int main(){
	pthread_t thread1,thread2;
	sem_init(&mutex,0,1);

	pthread_create(&thread1, NULL,t1, NULL);
	pthread_create(&thread2, NULL, t2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2, NULL);

	sem_destroy(&mutex);
	printf("\n");
	
}
