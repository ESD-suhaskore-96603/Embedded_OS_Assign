#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	int ret,status;
	printf("program started\n");
	for(int i=0;i<5;i++)
	{
		ret=fork();
		if(ret==0)
		{
			for(int i=0;i<5;i++)
			{
				printf("child (%d) (%d) : i =%d\n",getpid(),getppid(),i);
				sleep(1);
			}
			exit(0);
		}
		else
		{
			for(int i=0;i<5;i++)
			{
				wait(&status);
//				printf("exit status of child =%d\n",WEXITSTATUS(status));
					sleep(1);
				
			}
			 printf("exit status of child =%d\n",WEXITSTATUS(status));
		}
	}
	printf("Program finished\n");

}
