#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAX_MSG_SIZE 1000
int main()
{
	int sockfd;
	struct sockaddr_in server,client;
	int c,client_sock,port;
	char *outbox=(char *)malloc(MAX_MSG_SIZE),inbox[MAX_MSG_SIZE],ip[25];
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
		perror("Error in socket creation");
	else{
		server.sin_family=AF_INET;
		printf("Enter the IP Address :");
		scanf("%s",ip);
		server.sin_addr.s_addr=inet_addr(ip);
		printf("Enter the port : ");
		scanf("%d",&port);
		server.sin_port=htons(port);
		if((connect(sockfd,(const struct sockakaddr*)&server,sizeof(server)))==-1)
			perror("Error in connecting");
		else{
			printf("Connected");
			while(1){
				printf("You :");
				gets(outbox);
				if(send(sockfd,outbox,MAX_MSG_SIZE,0)==-1)
					perror("Send failed");
				if(recv(sockfd,inbox,MAX_MSG_SIZE,0)!=0)
					printf("Server : %s\n",inbox);
			}
		}
	}
	close(sockfd);
}
