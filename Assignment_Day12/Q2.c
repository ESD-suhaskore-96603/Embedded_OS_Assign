#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(void)
{
	int s;
	printf("program started\n");
	if(fork()==0)
	{
		if(fork()==0)
		{
			if(fork()==0)
			{
				for(int i=0;i<=5;i++)
				{
					                    printf("Process D (PID: %d, PPID: %d) count: %d\n", getpid(), getppid(), i);
sleep(1);
				}
				exit(0);
			}
			for(int i=0;i<=4;i++)
			{
				                    printf("Process C (PID: %d, PPID: %d) count: %d\n", getpid(), getppid(), i);
sleep(1);
			}
		
		wait(&s);
		exit(0);
	}
		for(int i=0;i<=4;i++)
		{
			                    printf("Process B (PID: %d, PPID: %d) count: %d\n", getpid(), getppid(), i);
					    sleep(1);
		}
		wait(&s);
		exit(0);
	}

	                    printf("Process A (PID: %d, PPID: %d) ", getpid(), getppid());
wait(&s);
  printf("All processes finished. Parent (A) exiting.\n");
}

		
