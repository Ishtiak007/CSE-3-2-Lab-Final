#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int global_var=10;
void child_process(){
int local_var=30;
local_var+=5;
global_var+=5;
printf("Child process:pid(%d)\n",getpid());
printf("Global Variable: %d\n", global_var);
printf("Local Variable: %d\n", local_var);
}
void parent_process(){
int local_var=30;
global_var+=10;
local_var+=10;
printf("Parent process:pid(%d)\n",getpid());
printf("Global variable:%d\n",global_var);
printf("Local variable:%d\n",local_var);
}
int main(){
pid_t pid=fork();
if(pid<0){
perror("fork faild");
exit(1);
}else if(pid==0){
child_process();


}else{
parent_process();
wait(NULL);
}





}
