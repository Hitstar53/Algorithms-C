#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
    pid_t pid;
    printf("Before Fork\n");
    pid = fork();
    if(pid==0) {
        sleep(15);
        printf("This is child process: %d\n",getpid());
        printf("This is child's parent: %d\n",getppid());
    }
    else if(pid>0) {
        sleep(15);
        // wait(NULL);
        printf("This is parent process: %d\n",getpid());
        printf("This is child of the parent: %d\n",pid);
    }
    else {
        printf("System failure");
    }
    printf("This is a common statement\n");
    return 0;
}
