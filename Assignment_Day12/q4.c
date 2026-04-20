#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
	int ret,s;
	ret=fork();
	if(ret==0)
	{
	//	char *argv[]={"www.google.com",NULL};
	//	execvp("www.google.com",argv);
	        execl("/usr/bin/google-chrome","google-chrome","google.co.in/maps",NULL);
	}
	else
	{
		wait(&s);
		printf("exit status of child process : %d\n", WEXITSTATUS(s));
	}

}
