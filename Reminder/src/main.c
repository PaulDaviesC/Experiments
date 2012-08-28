#include "timer.h"
#include "show.h"
#include<stdio.h>
#include<signal.h>
void alrm()
{
	int r;
	static int i=0;
	i++;
	char t[2];
	r=display("Hey","Turn your neck!Blink your eyes");
}
void main()
{
	countDown(60*30);//Notify once in 30*60 seconds/30 minutes
	signal(SIGALRM,alrm);
	while(1);
}
