#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<string.h>
#define Max_Txt 100
struct my_msg{
long int msg_type;
char some_text[Max_Txt];
};
int main(){
int running=1;
int msgid;
char buff[20];
struct my_msg my_data;
msgid=msgget((key_t)12345,0666|IPC_CREAT);
if(msgid==-1){
printf("Mas q create faild\n");
}
while(running){

msgrcv(msgid,(void*)&my_data,BUFSIZ,0,0);
printf("Data received:%s\n",my_data.some_text);
if(strncmp(buff,"end",3)==0){
running = 0;
}
}
msgctl(msgid,IPC_RMID,0);
}
