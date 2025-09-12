#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[100];

    pipe(fd); // pipe তৈরি
printf("%d\n",fd[1]);
    pid = fork(); // parent-child process তৈরি
	printf("%d\n",fd[0]);
    if (pid == 0) {
        // Child process: read from pipe
        close(fd[1]); // write end বন্ধ
        read(fd[0], buffer, sizeof(buffer));
        printf("Child read: %s\n", buffer);
    } else {
        // Parent process: write to pipe
        close(fd[0]); // read end বন্ধ
        char msg[] = "Hello from parent!";
        write(fd[1], msg, strlen(msg)+1);
    }

    return 0;
}
