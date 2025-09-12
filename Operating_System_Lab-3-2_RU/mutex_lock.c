#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int shared=1;
pthread_mutex_t l;
void* func1(){
        pthread_mutex_lock(&l);
        int x=shared;
        printf("th1 read shared as: %d\n",x);
        x++;
        printf("Incremented value by th1: %d\n",x);
        sleep(1);
        shared=x;
        printf("Updated value by th1 : %d\n",shared);
        pthread_mutex_unlock(&l);
        return NULL;
}

void* func2(){
        pthread_mutex_lock(&l);
        int y=shared;
        printf("th2 read shared as: %d\n",y);
        y--;
        printf("Incremented value by th2: %d\n",y);
        sleep(1);
        shared=y;
        printf("Updated value by th2 : %d\n",shared);
        pthread_mutex_unlock(&l);
        return NULL;
}

int main(){
pthread_mutex_init(&l,NULL);
pthread_t th1,th2;
pthread_create(&th1,NULL,func1,NULL);
pthread_create(&th2,NULL,func2,NULL);
pthread_join(th1,NULL);
pthread_join(th2,NULL);
printf("final value of shared: %d",shared);





}
