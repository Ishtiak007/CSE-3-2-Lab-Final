#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
int fd[2],n;
char buffer[100];
pid_t p;
pipe(fd);
p=fork();
if(p>0){
printf("Passing value to child\n");
write(fd[1],"hello\n",6);
}else{
printf("child received data.\n");
n=read(fd[0],buffer,100);
printf("%s",buffer);
}
}
