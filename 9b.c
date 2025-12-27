#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define SIZE 100

typedef struct{
int input[SIZE], output[SIZE],n;
}Data;

void sort(int arr[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]> arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

}

void *fill_odd(void *arg){
	Data *d = (Data*)arg;
	int n = d->n;
	int* arr = (int*)malloc(n*sizeof(int));

	for(int i=0; i<n; i++) arr[i] = d->input[i];
	sort(arr,n);
	for(int i=1; i<n; i+= 2)
		d->output[i] = arr[i];
	free(arr);
	pthread_exit(NULL);
}
void *fill_even(void *arg){
	Data *d = (Data*)arg;
	int n = d->n;
	int* arr = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) arr[i] = d->input[i];
	sort(arr,n);
	for(int i=0; i<n; i+= 2)
		d->output[i] = arr[i];
	free(arr);
	pthread_exit(NULL);
}
int main(){
	pthread_t t1,t2;
	Data d;
	int n;
	printf("Enter number of integers: \n");
	scanf("%d", &n);
	d.n = n;
	for(int i=0; i<n; i++) scanf("%d", &d.input[i]);
	for(int i=0; i<n; i++) d.output[i]=0;
	
	pthread_create(&t1, NULL,fill_odd,&d);
	pthread_create(&t2, NULL,fill_even,&d);
	
	pthread_join(t1,NULL);
	pthread_join(t2, NULL);
	
	printf("Output array: ");
	for(int i=0; i<n; i++){
		printf("%d ", d.output[i]);
		
	}
	printf("\n");
	return 0;
}
	
