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
        while(1){
        printf("p3: pid %d ppid %d\n" ,getpid(),getppid());
        sleep(1);
        }
    }
    }

    if(pid==0){
        pid=fork();
        if(pid==0){
        while(1){
        printf("p4: pid %d ppid %d\n" ,getpid(),getppid());
        sleep(1);
        }
    }

    if(pid>0){
        pid = fork();
        if(pid == 0){
            while(1){
            printf("p5:. pid %d ppid %d\n" ,getpid() ,getppid());
            sleep(1);
            }
        }
        if(pid>0){
            while(1){
            pid=fork();
            printf("p2: pid %d ppid %d\n",getpid() ,getppid());
            sleep(1);
            }
        }
    }
    }
    return 0;
}
