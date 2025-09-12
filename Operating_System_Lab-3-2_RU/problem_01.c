#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	
	int a=10,b=5;
	pid_t p;

	printf("this is parent process PID:%d\n",getpid());
	for(int i=0;i<3;i++){
		p=fork();
		if(p<0){
		   perror("fork faild");
		   exit(1);
		}else if(p==0){
			sleep(5);
		    printf("child PID:%d ,parent PID: %d\n",getpid(),getppid());
		    if(i==0){
			printf("Summation: %d+%d= %d\n",a,b,a+b);
		     }
	            if(i==1){
                         printf("Subtraction: %d-%d= %d\n",a,b,a-b);
                    }
		    if(i==2){
                        printf("Multiplication: %d*%d= %d\n",a,b,a*b);
                        }
			exit(0);
		}
		
	}
	

for(int i=0;i<3;i++){

	wait(NULL);
}

printf("Parent process end(PID:%d).\n",getpid());
return 0;



}
