#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int *fib;
int n;
void* fibonacci(){
	if(n>=1) fib[0]=0;
	if(n>=2) fib[1]=1;
	for(int i=2;i<n;i++){
	fib[i]=fib[i-1]+fib[i-2];
	}
	pthread_exit(NULL);
}
int main(int argc,char* argv[]){
if(argc!=2){
printf("Uaage:%s <number_of_terms>\n",argv[0]);
return 1;
}
n=atoi(argv[1]);
if(n<=0){
printf("please enter  positive number\n");
return 1;
}
fib=malloc(sizeof(int)*n);
pthread_t th;
pthread_create(&th,NULL,fibonacci,NULL);
pthread_join(th,NULL);
printf("FIbonaci series: ");
for(int i=0;i<n;i++){
printf("%d ",fib[i]);
}
printf("\n");
return 0;

}
