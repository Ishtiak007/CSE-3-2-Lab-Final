#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
int res ;
res = mkfifo("fifo2",0777);
printf("Named pipe created\n");
}
