#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
void countDown(int seconds)
{	
	struct timeval *p=(struct timeval *)malloc(sizeof(struct timeval));
	struct itimerval *i,*j=(struct itimerval*)malloc(sizeof(struct itimerval));
	j->it_value.tv_sec=seconds;
	j->it_value.tv_usec=seconds*1000;
	j->it_interval.tv_sec=seconds;
	j->it_interval.tv_usec=seconds*1000;
	setitimer(ITIMER_REAL,j,NULL);
}
