#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct timeval *p=(struct timeval *)malloc(sizeof(struct timeval));
	int i;
	for(;;){
		gettimeofday(p,NULL);
		printf("Time : %ld\n",p->tv_sec);
		for(i=0;i<1111111;i++);
	}
}
