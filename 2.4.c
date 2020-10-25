#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask(){
	char name[20];
	printf("ENTER NAME: ");
	fgets(name, sizeof(name), stdin);
	printf("\nMy name is ");
	puts(name);
	printf("My child process => PPID=%d, PPID=%d\n\n",getppid(), getpid());
	exit(0);
}

void parentTask(){
	printf("Parent process =>PID=%d\n", getpid());
	printf("All child process is done!\n");
	printf("Job is done\n\n");
}

void waiting(){
	printf("child process is waiting to finish.....");
	wait(NULL);
	printf("Child process FINISH!\n");
	printf("\n");
	printf("\n");
}

int main(void){

	for(int i=1; i<5; i++){
		pid_t pid = fork();
		if(pid == 0){
			childTask();
		}else if(i == 4){
			waiting();
			parentTask();
		}else waiting();
	}
	return EXIT_SUCCESS;
}
