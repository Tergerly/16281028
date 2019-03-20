#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    printf("p1: pid %d ppid %d\n",getpid(),getppid());
    pid = fork();
    if(pid>0){
    pid = fork();
    if(pid==0){
        printf("p3: pid %d ppid %d\n" ,getpid(),getppid());
    }
    if(pid>0){
        pid = fork();
        if(pid == 0){
            printf("p2:. pid %d ppid %d\n" ,getpid() ,getppid());
            pid = fork();
        if(pid==0){
            printf("p4: pid d ppid %d\n" ,getpid() ,getppid());
        }
        if(pid>0){
            pid=fork();
        if(pid==0){
            printf("p5: pid %d ppid %d\n",getpid() ,getppid());
        }
        }
        }
    }
    }
    return 0;
}
