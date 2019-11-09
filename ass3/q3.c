#include  <stdio.h>
#include  <sys/types.h>

#define   MAX  20

void  ChildProcess(pid_t);
void  ParentProcess(pid_t);           

void  main()
{
    pid_t  pid, parentId;
     
    parentId = getpid();
    pid = fork();
    if(pid == 0)
    	ChildProcess(parentId);
    else
       	ParentProcess(pid);
     
}

void  ChildProcess(pid_t id)
{
       	int i;
      	
	sleep(2);
	
	printf("In Child Process\n");
      	printf("Process Id = %d\tParent Process Id = %d\n",getpid(),id);
       
	for(i=1;i<=MAX;i+=2)
        	printf("Child Process value = %d\n", i);
       
}

void  ParentProcess(pid_t id)
{
       	int i;
       
	sleep(1);

	printf("In Parent Process\n");
       	printf("Process Id = %d\tChild Process Id = %d\n",getpid(),id);
	
	for(i=2;i<=MAX;i+=2)
        	printf("Parent Process value = %d\n", i);
	wait(0);
}
