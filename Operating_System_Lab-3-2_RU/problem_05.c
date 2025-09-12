#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>
int main(int argc,char *argv[]){
	if(argc<3){
	printf("Usage:%s<n><child_1> <child_2> .....<child_n>\n",argv[0]);
	return 1;
	}
	int n=atoi(argv[1]);
	if(argc !=n+2){
	printf("Error: Expected %d child names, but got %d\n",argc-2,n);
	return 1;
	}
        printf("Parent process:parent_process (PID:%d)\n",getpid());
        pid_t pid;
        for(int i=0;i<n;i++){
        pid=fork();
        if(pid==0){
        printf("child process name:%s(PID:%d) parent pid:%d\n",argv[i+2],getpid(),getppid());
        sleep(2);
	exit(0);
        }

        }
	for(int i=0;i<n;i++)
		wait(NULL);
	return 0;
}
