#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{

        pid_t q;
        printf("Before fork\n\n");
        q=fork();
        if(q==0){
                printf("I am child process having id: %d\n",getpid());
                printf("My parent's parent id: %d\n",getppid());
        }else if(q>0){
		
                printf("I am parent process having id: %d\n",getpid());
                wait(NULL);
		printf("My child's id: %d\n",q);


        }

        printf("Common\n\n\n");



}
