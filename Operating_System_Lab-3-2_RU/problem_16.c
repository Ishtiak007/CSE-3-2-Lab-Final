#include <stdio.h>
#include <pthread.h>
int counter=1;
pthread_mutex_t l;
void* increment_counter(){
	pthread_mutex_lock(&l);
	int x=counter;
	x++;
	counter=x;
	printf("Thread 1  update counter value:%d\n",counter);
	pthread_mutex_unlock(&l);
}
void* decrement_counter(){
        pthread_mutex_lock(&l);
        int x=counter;
        x--;
        counter=x;
        printf("Thread 2  update counter value:%d\n",counter);
        pthread_mutex_unlock(&l);
}
int main(){
pthread_t t1,t2;
pthread_mutex_init(&l,NULL);
pthread_create(&t1,NULL,increment_counter,NULL);
pthread_create(&t2,NULL,decrement_counter,NULL);
pthread_join(t1,NULL);
pthread_join(t1,NULL);
printf("Final counter value:%d\n",counter);
pthread_mutex_destroy(&l);
return 0;


}
