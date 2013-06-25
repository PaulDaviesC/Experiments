#include<stdio.h>
#include<fcntl.h>
int main()
{
	char buff[]="IPCD";
	int fd=open("/dev/ipcdev",O_WRONLY);
	write(fd,buff,4);
	return 0;
}
