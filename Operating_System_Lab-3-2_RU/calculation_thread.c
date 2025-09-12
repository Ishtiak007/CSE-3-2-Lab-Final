#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int num[2]={10,5};
void *summation(void *arg){
	int *x=arg;
	int *sum=malloc(sizeof(int));
	*sum=x[0]+x[1];
	printf("Inside thread Sum: %d\n",*sum);
	pthread_exit((void *)sum);

}
void *multiplication(void *arg){
        int *x=arg;
        int *sum=malloc(sizeof(int));
        *sum=x[0]*x[1];
        printf("Inside thread Mul: %d\n",*sum);
        pthread_exit((void *)sum);

}
int main(){
	void *sum;
	pthread_t thread_sum;
	pthread_create(&thread_sum,NULL,summation,(void *)num);
	pthread_join(thread_sum,&sum);
	int y=*(int *)sum;
	printf("Inside program sum:%d\n",y);


void *mul;
        pthread_t thread_mul;
        pthread_create(&thread_mul,NULL,multiplication,(void *)num);
        pthread_join(thread_mul,&mul);
         y=*(int *)mul;
        printf("Inside program mul:%d\n",y);
}
