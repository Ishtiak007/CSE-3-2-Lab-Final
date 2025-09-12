#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(){
int res,n;
char buff[100];
res=open("fifo2",O_RDONLY);
n=read(res,buff,100);
printf("Receved data by process(pid:%d) :%s\n",getpid(),buff);
//write(1,buff,n);


}
