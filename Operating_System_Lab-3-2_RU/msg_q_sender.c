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
printf("Enter a message\n");
fgets(buff,20,stdin);
my_data.msg_type=1;
strcpy(my_data.some_text,buff);
//printf("%s",my_data.some_text);
//int msgsnd(int msqid, const void msgp[.msgsz], size_t msgsz,int msgflg);
if(msgsnd(msgid,(void*) &my_data,Max_Txt,0)==-1){
	printf("Msg not send\n");
}
if(strncmp(buff,"end",3)==0){
running = 0;
}
}

}
