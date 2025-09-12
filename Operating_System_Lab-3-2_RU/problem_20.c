#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int *number;
int count;
double avg;
int minimum;
int maximum;
void* calc_avg(){
	int sum=0;
	for(int i=0;i<count;i++){
	sum+=number[i];
	}
	avg=(double)sum/count;
	pthread_exit(0);

}
void* calc_max(){
        int max=number[0];
	for(int i=1;i<count;i++){
	if(max<number[i])
	max=number[i];
	}
	maximum=max;
        pthread_exit(0);

}
void* calc_min(){
        int min=number[0];
        for(int i=1;i<count;i++){
        if(min>number[i])
        min=number[i];
        }
	minimum=min;
        pthread_exit(0);

}
int main(int argc,char* argv[]){
if(argc<2){
printf("Number of elament at  least 2");
return 1;
}
count = argc-1;
number=malloc(sizeof(int)*count);
for(int i=0;i<count;i++){
number[i]=atoi(argv[i+1]);
}
for(int i=0;i<count;i++){
printf("%d\n",number[i]);
}
pthread_t t1,t2,t3;
pthread_create(&t1,NULL,calc_avg,NULL);
pthread_create(&t2,NULL,calc_max,NULL);
pthread_create(&t3,NULL,calc_min,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);

printf("Avarage value:%.0f\n",avg);
printf("Maximum vlue:%d\n",maximum);
printf("Minimum vlue:%d\n",minimum);
}
