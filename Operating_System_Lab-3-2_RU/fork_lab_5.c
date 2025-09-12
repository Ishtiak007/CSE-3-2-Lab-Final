#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{

	pid_t q;
	printf("Before fork\n\n");
	q=fork();
	if(q==0){
		printf("I am child process having id: %d\n",getpid());
		printf("I am parent id: %d\n",getppid());
	}else if(q>0){
		printf("I am parent process having id: %d\n",getppid());
                printf("I am child's id: %d\n",getpid());


	}

	printf("Common");



}
