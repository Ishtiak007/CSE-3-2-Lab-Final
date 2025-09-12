#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{

        pid_t q;
        printf("Before fork\n\n");
        q=fork();
        if(q==0){
                sleep(5);
                printf("I am child process having id: %d\n",getpid());
                printf("I am parent id: %d\n",getppid());
                printf("Child terminated\n");
        }else if(q>0){
                sleep(10);
                printf("I am parent process having id: %d\n",getpid());
                printf("My child's id: %d\n",q);
                printf("Parent terminated\n");


        }

        printf("Common\n\n");



}
