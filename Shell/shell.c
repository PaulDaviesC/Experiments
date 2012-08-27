#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[]="/bin/%s",*arg=(char *)malloc(15*sizeof(char)),*cmd=(char *)malloc(15*sizeof(char)),*cmdarg=(char *)malloc(15*sizeof(char)),*cwd=(char *)malloc(70*sizeof(char));
	while(1){
		printf("paul@linux:~%s$ ",getcwd(cwd,70));
		cmdarg=gets(cmdarg);
		cmd=(char *)strtok(cmdarg," ");
		arg=(char *)strtok(NULL," ");
		if(strcmp("cd",cmd)==0){
			if(chdir(arg)==-1)
				perror("Error");
		}
		else if(strcmp("exit",cmdarg)==0) //Type exit to Exit ;)
				kill(getpid(),9);
		else{
			if(fork()==0){
				sprintf(path,"/bin/%s",cmd);
				if(execl(path,cmd,arg,(char *)NULL)==-1)
					perror("No such command in /bin");
			}
			else
				wait();
		}
	}
}
