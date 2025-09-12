#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
      	printf("Parent process:parent_process (PID:%d)\n",getpid());
	pid_t pid;
	int n;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++){
	pid=fork();
	if(pid==0){
	printf("child process name:child_%d(PID:%d) parent pid:%d\n",i,getpid(),getppid());
	exit(0);
	}

	}
}
