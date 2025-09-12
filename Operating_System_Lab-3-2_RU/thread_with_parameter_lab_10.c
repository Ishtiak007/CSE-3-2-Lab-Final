#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int num[2]={3,5};
void *thread_function(void *arg){

        printf("Inside Thread\n");
        int *x=arg;
	int *sum=malloc(sizeof(int));
	*sum=x[0]+x[1];
	
	printf("%d\n",*sum);
	pthread_exit((void*) sum);
}

int main(){
	void *sum;
        pthread_t a_thread;
        pthread_create(&a_thread,NULL,thread_function,(void *)num);
        pthread_join(a_thread,&sum);
        printf("Inside main program\n");
        printf("Sum: %d\n",*(int*)sum);


}
