#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
int res ,n;
res =open("fifo2",O_NONBLOCK,O_WRONLY);
write(res,"New data\n",9);
printf("Sender sent data\n");

}
