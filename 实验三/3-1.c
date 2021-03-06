#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
pthread_mutex_t mutex;
pthread_mutex_init(&mutex,NULL); //初始化互斥锁mutex
printf("I'm father\n");//父进程

pid_t pid1 = fork();	//fork方式创建子进程
if(pid1 == 0){
	printf("I am the process P1\n");
	return 0;
}

waitpid(pid1, NULL, 0);	//等待P1进程结束再继续
pid_t pid2 = fork();
if(pid2 == 0){
	pthread_mutex_lock(&mutex);	//加锁实现P2、P3进程互斥
	printf("I am the process P2\n");
	pthread_mutex_unlock(&mutex);
	return 0;
}

waitpid(pid1, NULL, 0);
pid_t pid3 = fork();
if(pid3 == 0){
	pthread_mutex_lock(&mutex);
	printf("I am the process P3\n");
	pthread_mutex_unlock(&mutex);
	return 0;
}

waitpid(pid2, NULL, 0);
waitpid(pid3, NULL, 0);
pid_t pid4 = fork();
if(pid4 == 0){
	printf("I am the process P4\n");
	return 0;
}

else if(pid1 != -1){
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	waitpid(pid4, NULL, 0);	//等待所有子进程结束
	//printf("Process exited.\n");
}
 
pthread_mutex_destroy(&mutex);//销毁互斥锁
return 0;
}
