#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
int main(){
int res,n;
char buff[100];
res=mkfifo("fifo3",0777);
if(res==-1){
perror("mkfifo error");
}
pid_t pid;
pid=fork();
if(pid>0){
int fd=open("fifo3",O_WRONLY);
char *message="Hello from parent process";
write(fd,message,strlen(message)+1);
close(fd);
wait(NULL);

}else{
//child process
int fd=open("fifo3",O_RDONLY);
n=read(fd,buff,sizeof(buff));
printf("Child received:%s\n",buff);
close(fd);

}


}
