#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
int shmid;
int *shared_memory;
//create shm
shmid=shmget((key_t)1122,sizeof(int),0666|IPC_CREAT);
if(shmid<0){
perror("shm create fail");
exit(1);
}
//attach  shm
shared_memory=(int *)shmat(shmid,NULL,0);
*shared_memory=0;
pid_t pid;
if(pid<0){
perror("fork faild");
exit(1);
}
for(int i=0;i<100000;i++)
	(*shared_memory)++;
if(pid==0){
	shmdt(shared_memory);
	exit(0);
}else{
wait(NULL);
printf("Final value if shared memory:%d\n",*shared_memory);
shmdt(shared_memory);
shmctl(shmid,IPC_RMID,NULL);
}



}
