#include<stdio.h>
#include<unistd.h>

int main(){
	int n;
	char buff[30];
	n=read(0,buff,10);
	write(1,buff,n);






}
