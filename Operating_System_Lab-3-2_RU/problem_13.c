#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int shared=1;
void* increment(){
int x=shared;
printf("T1 read :%d\n",x);
x++;
printf("local udated:%d\n",x);
sleep(1);
shared=x;
printf("Shared updated:%d\n",shared);
return 0;
}
void* decrement(){
int x=shared;
printf("T2 read :%d\n",x);
x--;
printf("local udated:%d\n",x);
sleep(1);
shared=x;
printf("Shared updated:%d\n",shared);
return 0;
}
int main(){

pthread_t t1,t2;

pthread_create(&t1,NULL,increment,NULL);
pthread_create(&t2,NULL,decrement,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("Final value of counter:%d\n",shared);
return 0;

}
