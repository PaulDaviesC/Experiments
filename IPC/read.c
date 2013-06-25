#include<stdio.h>
#include<fcntl.h>
int main()
{
	char buff[4];
	int fd=open("/dev/ipcdev",O_RDONLY);
	read(fd,buff,4);
	printf("Read %s\n",buff);
	return 0;
}
