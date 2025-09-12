#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	printf("Befor fork\n");
	pid_t pid;
	pid=fork();
	if(pid<0){
	perror("fork faild");
		exit(1);
	}
	else if(pid>0){
	sleep(1);
	printf("This is parent process having PId: %d\n",getpid());
	}else{
	sleep(10);
	printf("This is a orphan process having pid:%d\n",getpid());
	printf("Parent PID: %d\n",getppid());
	

	}


}
