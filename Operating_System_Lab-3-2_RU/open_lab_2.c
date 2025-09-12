#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	int n,fd;
	char buf[50];
	fd=open("test.txt",O_RDONLY);
	n=read(fd,buf,10);
	int fd1=open("target",O_CREAT|O_WRONLY,0642);
	write(fd1,buf,n);



}
